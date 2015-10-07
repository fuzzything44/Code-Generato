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
    ENTER_FUNC("globalNamespace::globalNamespace()")    
    
    LOG("Creating basic data types" << std::endl)
    // Initialize basic data types.
    
    // classDef takes:
    // std::string name, std::vector<classDef> parents, std::vector<function> funcs, std::vector<classDef> templateArguments
    
    // function takes:
    // std::string name, std::vector<classDef>& templateArgs, std::vector<classDef>& args, classDef ret
    
    
    // Create void
    {
        LOG("Creating void")
        classDef* voidClass = new classDef("void");
        types.push_back(voidClass);
        LOG("Finished void" << std::endl)
    }
    
    // Create bool
    {
        LOG("Creating bool")
        classDef* boolClass = new classDef("bool");
        
        // Operators needed:
        // =     ==     !     !=
        types.push_back(boolClass);
        LOG("Finished bool" << std::endl)
    }
    
    // Create int
    {
        LOG("Creating int")
        classDef* intClass = new classDef("int");
        
        // Operators needed:
        // +     -     /     *     +=     -=     *=     /=     =     ==
        delete intClass;
        LOG("int left unfinished...")
    }
    
    // Create char
    {
        LOG("Creating char")
        classDef* charClass = new classDef("char");
        types.push_back(charClass);
        LOG("Finished Char")
    }
    
    // Create float
    {
        LOG("Creating float")
        classDef* floatClass = new classDef("float");
        types.push_back(floatClass);
        LOG("Finished float")
    }
    
    LOG("Finished creating basic data types" << std::endl << std::endl)
    LEAVE_FUNC_VOID("globalNamespace::globalNamespace()")
}

void globalNamespace::generate(int32 length)
{
    ENTER_FUNC("globalNamespace::generate(int32 length)")
    // And now we generate!
    LOG("Generating code with length " << length)
    
    for(; length > 0; length--) {        
        // We can create a class or a function.
        if (randRange(0,1) == 0)
        {
            LOG("Generating class...")
            // We create the class. It has its own scope.
            classScope c{ this };
            const classDef* gen = c.generate();
            types.push_back(gen);
            // Add the destroyer.
            destructor<const classDef>* d = new destructor<const classDef>(gen);
            death.push_back(d);
            LOG("Class finished!")
            
        } else {
            LOG("Generating function...")
            // We create the function. It has its own scope.
            functionScope f{ this };
            const function* gen = f.generate();
            functions.push_back(gen);
            // Add the destroyer.
            destructor<const function>* d = new destructor<const function>(gen);
            death.push_back(d);
            LOG("Function finished!")
        }
    }
    
    LOG("Finished all classes and functions. Generating main")
    // Generate main. Pretty much a function generate, just with a set name.
    CODE("int main()")
    CODE("{")
    CODE("\t" << types[types.size() -1]->getName() << "{};")
    CODE("\treturn 0;")
    CODE("}")
    
    LEAVE_FUNC_VOID("globalNamespace::generate(int32 length)")
    
}

globalNamespace::~globalNamespace()
{
    ENTER_FUNC("globalNamespace::~globalNamespace()")
    
    // Delete death.
    for (auto i = death.begin(); i != death.end(); i++) {
        delete *i;
    }
    LEAVE_FUNC_VOID("globalNamespace::~globalNamespace")
}


