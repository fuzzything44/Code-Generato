#include "classScope.h"
#include "logger.h"
#include "variableNamer.h"

using std::string;
using std::vector;

classScope::classScope(globalNamespace* parent)
{
    functions = parent->functions;
    types = parent->types;
}

classDef classScope::generate()
{
    // Create class being generated.
    string name = genName::get("class");
    classDef ret { name };
    
    // Decide if we will have parents.
    if (randRange(0, 10) == 0 && types.size() > 0) {
        // Determine what parents. Currently we just have one.
        classDef parent = types[randRange(0, types.size() - 1)];
        ret.addParent(parent);
        CODE("class " << name << " : public " << parent.getName() )
    } else {
        CODE("class " << name)
    }
    CODE("{")
    
    // Now that we have parents, we can determine what functions we generate.
    // Start with not caring about parent functions & inheritance.
    // Any private variables will not be added to ret.
    
    CODE("private:")
    
    // Determine number of private variables.
    LOG("Creating private variables (not functions)" )
    for (int i = randRange(1, 10); i > 0; i--) {
        // Choose random type.
        classDef type = types[randRange(0, types.size() - 1)];
        
        // Choose name.
        string name = genName::get(type.getName());
        
        // Print it out.
        CODE(type.getName() << " " << name << ";")
        
        // Add it to variables available.
        
    }
    
    LOG("Creating private functions")
    // Determine number of functions
    for (int i = randRange(0, 10); i > 0; i--) {
        // Create a function
        functionScope f(this);
        // Add generated function to given functions.
        functions.push_back(f.generate());
    }
    
    LOG("Creating public variables")
    CODE("public:")
    
    // Create public variables.
    for (int i = randRange(0, 10); i > 0; i--) {
        // Create variable parameters.
        classDef& type = types[randRange(0, types.size() - 1)];
        string varName = genName::get(type.getName() );
        
        // Create variable and add it.
        classDef::variable var{ varName, type };
        variables.push_back(var);
        ret.addVar(var);
        
        // Output it.
        CODE(type.getName() << " " << varName << ";");
    }
    
    // Create public functions.
    for (int i = randRange(0, 10); i > 0; i--) {
        // Make it
        functionScope f{ this };
        function func = f.generate();
        // Add it
        functions.push_back(func);
        ret.addFunction(func);
    }
    
    
    // Create constructor...
    // We only have one now. Just basic constructor.
    CODE(name << "() {}")
    // Cheese function. Just name and return of void.
    ret.addFunction(function{ name, vector<classDef>(), vector<classDef>(), types[0] } );
    CODE("};")
    return ret;
}