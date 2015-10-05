#include "classScope.h"
#include "logger.h"
#include "genName.h"

using std::string;
using std::vector;

classScope::classScope(globalNamespace* parent)
{
    ENTER_FUNC("classScope::classScope(globalNamespace* parent)")
    parentFuncs = &(parent->functions);
    types = &(parent->types);
    LEAVE_FUNC_VOID("classScope::classScope(globalNamespace* parent)")
}

classDef* classScope::get_random_type()
{
    ENTER_FUNC("classScope::get_random_type()")
    LEAVE_FUNC("classScope::get_random_type()", (*types)[randRange(0, types->size() - 1)].get() )
}

function* classScope::get_random_func()
{
    ENTER_FUNC("get_random_func()")
    if (functions.size() == 0) {
        if ((*parentFuncs).size() == 0) {
            // Neither have a size.
            LEAVE_FUNC("classScope::get_random_func()", nullptr)
        } else {
            // parentFuncs has a size.
            LEAVE_FUNC("classScope::get_random_func()", (*parentFuncs)[randRange(0, parentFuncs->size() - 1) ].get() )
        }
    } else if ((*parentFuncs).size() == 0) {
        // functions has a size.
        LEAVE_FUNC("classScope::get_random_func()", functions[randRange(0, functions.size() - 1)])
    } else {
        // Both have a size.
        if (randRange(0, 1) == 0) {
            LEAVE_FUNC("classScope::get_random_func()", functions[randRange(0, functions.size() - 1)])
        } else {
            LEAVE_FUNC("classScope::get_random_func()", (*parentFuncs)[randRange(0, parentFuncs->size())].get())
        }
    }
}

classDef::variable classScope::get_random_var()
{
    ENTER_FUNC("classScope::get_random_var()")
    LEAVE_FUNC("classScope::get_random_var()", variables[randRange(0, variables.size() - 1)])
}

classDef* classScope::generate()
{
    ENTER_FUNC("classScope::generate()")
    // Create class being generated.
    string name = genName::get("class", types);
    classDef* ret = new classDef(name);
    
    LOG("Generating class with name " << name)
    
    CODE("class " << name)
    CODE("{")
    CODE("private:")
    
    // All lines now should have an extra indent.
    logger::code_pre += "\t";
    
    // Determine number of private variables.
    LOG("Creating private variables..." )
    while (randRange(0, 10) != 10) {
        // Choose random type.
        classDef* type = get_random_type();
        
        // Choose name.
        string name = genName::get(type->getName(), variables);
        
        // Print it out.
        CODE(type->getName() << " " << name << ";")
        
        // Add it to variables available.
        
        variables.push_back(classDef::variable(name ,type) );
        
    }
    
    LOG("Creating private functions...")
    // Determine number of functions
    while (randRange(0, 10) != 10) {
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
    while(randRange(0, 10) != 10) {
        // Create variable parameters.
        classDef* type = get_random_type();
        string varName = genName::get(type->getName(), variables);
        
        // Create variable and add it.
        classDef::variable var{ varName, type };
        variables.push_back(var);
        ret->addVar(var);
        
        // Output it.
        CODE(type->getName() << " " << varName << ";");
    }
    
    LOG("Creating public functions...")
    // Create public functions.
    for (int64 i = randRange(0, 10); i > 0; i--) {
        // Make it
        functionScope f{ this };
        function* func = f.generate();
        // Add it
        functions.push_back(func);
        ret->addFunction(func);
    }
    
    LOG("Creating constructor...")
    
    // Create constructor...
    // We only have one now. Just basic constructor.
    CODE(name << "() {}")
    // Cheese function. Just name and return of void.
    function* constructor = new function(name, vector<const classDef*>(), (*types)[0].get() );
    ret->addFunction(constructor);
    
    // Remove tab.
    logger::code_pre.pop_back();
    CODE("};")
    
    LOG("\n");
    LOG("Constructor not created (only default added.) \n")
    LEAVE_FUNC("classScope::generate()", ret)
    return ret;
}