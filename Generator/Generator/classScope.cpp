#include "classScope.h"
#include "logger.h"
#include "genName.h"

using std::string;
using std::vector;

classScope::classScope(globalNamespace* parent)
{
    ENTER_FUNC("classScope::classScope(globalNamespace* parent)")
    functions = parent->functions;
    types = parent->types;
    LEAVE_FUNC_VOID("classScope::classScope(globalNamespace* parent)")
}

classDef* classScope::generate()
{
    ENTER_FUNC("classScope::generate()")
    // Create class being generated.
    string name = genName::get("class", types);
    classDef ret { name };
    
    LOG("Generating class with name " << name)
    
    CODE("class " << name)
    CODE("{")
    CODE("private:")
    
    // All lines now should have an extra indent.
    logger::code_pre += "\t";
    
    // Determine number of private variables.
    LOG("Creating private variables..." )
    for (int64 i = randRange(1, 10); i > 0; i--) {
        // Choose random type.
        classDef type = types[randRange(1, types.size() - 1)];
        
        // Choose name.
        string name = genName::get(type.getName(), variables);
        
        // Print it out.
        CODE(type.getName() << " " << name << ";")
        
        // Add it to variables available.
        
        variables.push_back(classDef::variable(name ,type));
        
    }
    
    LOG("Creating private functions...")
    // Determine number of functions
    for (int64 i = randRange(0, 10); i > 0; i--) {
        // Create a function
        functionScope f(this);
        // Add generated function to given functions.
        functions.push_back(f.generate());
    }
    
    LOG("Creating public variables...")
    
    // Remove tab for public:
    logger::code_pre.pop_back();
    CODE("public:")
    // Add tab back
    logger::code_pre += "\t";
    
    // Create public variables.
    for (int64 i = randRange(0, 10); i > 0; i--) {
        // Create variable parameters.
        classDef type = types[randRange(1, types.size() - 1)];
        string varName = genName::get(type.getName(), variables);
        
        // Create variable and add it.
        classDef::variable var{ varName, type };
        variables.push_back(var);
        ret.addVar(var);
        
        // Output it.
        CODE(type.getName() << " " << varName << ";");
    }
    
    LOG("Creating public functions...")
    // Create public functions.
    for (int64 i = randRange(0, 10); i > 0; i--) {
        // Make it
        functionScope f{ this };
        function func = f.generate();
        // Add it
        functions.push_back(func);
        ret.addFunction(func);
    }
    
    LOG("Creating constructor...")
    
    // Create constructor...
    // We only have one now. Just basic constructor.
    CODE(name << "() {}")
    // Cheese function. Just name and return of void.
    ret.addFunction(function{ name, vector<classDef>(), types[0] } );
    
    // Remove tab.
    logger::code_pre.pop_back();
    CODE("};")
    
    LOG("\n");
    LOG("Constructor not created (only default added.) \n")
    LEAVE_FUNC("classScope::generate()", ret)
    return ret;
}