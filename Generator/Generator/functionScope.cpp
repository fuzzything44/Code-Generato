#include "functionScope.h"
#include "random.h"
#include <vector>
#include "variableNamer.h"
#include "logger.h"

using std::string;
using std::vector;

functionScope::functionScope(classScope* parent)
{
    functions = parent->functions;
    types = parent->types;
    variables = parent->variables;
}

functionScope::functionScope(globalNamespace* parent)
{
    functions = parent->functions;
    types = parent->types;
}


inline bool canCall(const vector<classDef::variable>& vars, const function& func)
{
    
    // Check all arguments of the function.
    for (vector<classDef>::const_iterator i = func.getArgs().begin(); i != func.getArgs().end(); i++) {
        // Check all variable types we have.
        for (vector<classDef::variable>::const_iterator j = vars.begin(); j != vars.end(); j++) {
            if (j->second == *i) {
                break;
            } else if ( j == --vars.end() ) {
                // We found no match for the variable.
                return false;
            }
        }
    }
    
    return true;
}









// Generating function.
function functionScope::generate()
{
    // Make name.
    string name = genName::get("function");
    
    // No template args.
    vector<classDef> templateArgs;
    
    vector<classDef::variable> argTypes;
    // Choose random arguments.
    vector<classDef> args;
    for (int argNum = randRange(0, 5); argNum > 0; argNum--) {
        // Choose argument type.
        classDef argType = types[randRange(1, types.size() - 1)];
        // Choose argument name.
        string argName = genName::get(argType.getName());
        
        // Add argument type.
        args.push_back(argType);
        
        // Add argument type and name to the argument array.
        argTypes.push_back(std::pair<string, classDef>(argName, argType));
        
    }
    
    // Choose random return type.
    classDef retType = types[randRange(0, types.size() - 1)];
    
    function ret(name, templateArgs, args, retType);
    
    // Format function name.
    {
        string funcName = retType.getName() + " " + name + "(";
        
        // loop through all arguments.
        for (vector<classDef::variable>::const_iterator i = argTypes.begin(); i != argTypes.end(); i++) {
            // If it's not the first argument, put a comma before it.
            if (i != argTypes.begin()) {
                funcName += ", ";
            }
            
            // Add the argument name. Type name and then variable name.
            funcName += i->second.getName() + " " + i->first;
        }
        // Output function name.
        CODE(funcName);
    }
    
    // Generate 10 to fifty statements/blocks.
    for (int length = randRange(10, 50); length > 0; length--) {
        // Choose if we generate a line or call a function.
        if ( randRange(0, 10) == 0) {
            // Find all functions we can call.
            vector<function> callable;
            for (vector<function>::const_iterator i = functions.begin(); i != functions.end(); i++) {
                if(canCall(variables, *i) ) {
                    callable.push_back(*i);
                }
            }
            // Now we call one...
            
            
            
            
            
            
            
            
            
            
            
        } else {
            // Generate a random line of code.
            
            
            
            
            
            
            
            
            
            
        }
        
        
        // Currently, we won't implement smallScope.
    }
    
    return ret;
}
