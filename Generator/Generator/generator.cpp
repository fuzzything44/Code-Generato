#include "generator.h"
#include "logger.h"
#include "function.h"
#include "classDef.h"
#include "random.h"
#include "variableNamer.h"

using std::vector;
using std::string;

globalNamespace::globalNamespace()
{
    // Start logging
    logger::init("generator");
    
    
    LOG("Creating basic data types" << std::endl)
    // Initialize basic data types.
    // classDef takes:
    // std::string name, std::vector<classDef> parents, std::vector<function> funcs, std::vector<classDef> templateArguments
    
    // function takes:
    // std::string name, std::vector<classDef>& templateArgs, std::vector<classDef>& args, classDef ret
    
    
    // Create void
    {
        LOG("Creating void")
        classDef voidClass{ "void", vector<classDef>(), vector<function>(), vector<classDef>() };
        types.push_back(voidClass);
        LOG("Finished void" << std::endl)
    }
    
    // Create bool
    {
        LOG("Creating bool")
        classDef boolClass{ "bool", vector<classDef>(), vector<function>(), vector<classDef>() };
        
        // Holds function arguments.
        vector<classDef> args;
        
        args.push_back(boolClass);
        // Operators included:
        // ==     =
        function opEq{ "operator==", vector<classDef>(), args, boolClass };
        function opSet{ "operator=", vector<classDef>(), args, boolClass };
        
        boolClass.addFunction(opEq);
        boolClass.addFunction(opSet);
        
        types.push_back(boolClass);
        LOG("Finished bool" << std::endl)
    }
    
    // Create int
    {
        LOG("Creating int")
        classDef intClass{ "int", vector<classDef>(), vector<function>(), vector<classDef>() };
        
        // Holds int function arguments.
        vector<classDef> args;
        
        // Operators needed:
        // +     -     /     *     +=     -=     *=     /=     =     ==
        
        LOG("int left unfinished...")
    }
    
    // Create char
    {
        LOG("char not added")
    }
    
    // Create float
    {
        LOG("float not added")
    }
    
    LOG("Finished creating basic data types" << std::endl << std::endl)
}


void globalNamespace::generate(int length)
{
    // And now we generate!
    
    // We can create a class or a function.
    if (randRange(0,1) == 0)
    {
        LOG("Generating class")
        // First we need a class name.
        string name = genName::getClass();
        
        // Now we create the class. It has its own scope.
        
        
    } else {
        LOG("Generating function")
        // First we need a function name.
        string name = genName::getFunc();
        
        // Now we create the function. It has its own scope.
    }
}