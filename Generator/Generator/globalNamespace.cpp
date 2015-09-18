#include "globalNamespace.h"
#include "logger.h"
#include "function.h"
#include "classDef.h"
#include "random.h"
#include "genName.h"

using std::vector;
using std::string;



// globalNamespace
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
        classDef voidClass{ "void",};
        types.push_back(voidClass);
        LOG("Finished void" << std::endl)
    }
    
    // Create bool
    {
        LOG("Creating bool")
        classDef boolClass{ "bool",};
        
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
        classDef intClass{ "int",};
        
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

void globalNamespace::generate(int32 length)
{
    // And now we generate!
    LOG("Generating code with length " << length)
    
    for(; length > 0; length--) {        
        // We can create a class or a function.
        if (randRange(0,1) == 0)
        {
            LOG("Generating class...")
            // We create the class. It has its own scope.
            classScope c{ this };
            types.push_back(c.generate() );
            LOG("Class finished!")
            
        } else {
            LOG("Generating function...")
            // We create the function. It has its own scope.
            functionScope f{ this };
            functions.push_back(f.generate() );
            LOG("Function finished!")
        }
    }
    
    LOG("Finished all classes and functions. Generating main")
    
    // Generate main. Pretty much a function generate, just with a set name.
    
}