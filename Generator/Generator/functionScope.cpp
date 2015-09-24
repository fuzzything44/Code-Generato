#include "functionScope.h"
#include "random.h"
#include <vector>
#include "genName.h"
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

inline bool canCall(const function func, const vector<classDef::variable> vars)
{
    LOG("Checking if function " << func.getName() << " can be called.")
    LOG("-Expected checks: " << (func.getArgs().size() * vars.size() ) )
    LOG("-Size of function args = " << func.getArgs().size() )
    LOG("-Size of variables = " << vars.size())
    // Check all arguments of the function.
    for (auto i = func.getArgs().cbegin(); i != func.getArgs().cend(); i++) {
        // Check all variable types we have.
        bool foundMatch = false;
        for (auto j = vars.cbegin(); j != vars.cend(); j++) {
            
            if ((*i >= j->second) || (*i == vars[1].second) ) {
                foundMatch = true;
                break;
            }
        }
        if (!foundMatch) {
            LOG("  No match found. Returning false.")
            return false;
        }
    }
    LOG("  Match found. Returning true.")
    return true;
}



// Generating function.
function functionScope::generate()
{
    // Make name.
    string name = genName::get("function", variables);
    
    LOG("Creating function " << name)
    
    LOG("Creating arguments...")
    vector<classDef::variable> argTypes;
    // Choose random arguments.
    vector<classDef> args;
    for (int64 argNum = randRange(0, 5); argNum > 0; argNum--) {
        // Choose argument type.
        classDef argType = types[randRange(1, types.size() - 1)];
        // Choose argument name.
        string argName = genName::get(argType.getName(), variables);
        
        // Add argument type.
        args.push_back(argType);
        
        // Add argument type and name to the argument array.
        argTypes.push_back(classDef::variable(argName, argType));
        
    }
    
    
    LOG("Creating return type...")
    // Choose random return type.
    classDef retType = types[randRange(0, types.size() - 1)];
    
    function ret(name, args, retType);
    
    LOG("Formatting function name...")
    // Format function name.
    {
        string funcName = retType.getName() + " " + name + "(";
        
        // loop through all arguments.
        for (auto i = argTypes.begin(); i != argTypes.end(); i++) {
            // If it's not the first argument, put a comma before it.
            if (i != argTypes.begin()) {
                funcName += ", ";
            }
            
            // Add the argument name. Type name and then variable name.
            funcName += i->second.getName() + " " + i->first;
        }
        // Output function name.
        CODE(funcName << ")");
    }
    CODE( "{" )
    // Add tab to all printed statements.
    logger::code_pre += "\t";
    
    LOG("Creating function body...")
    // Generate 10 to fifty statements/blocks.
    for (int64 length = randRange(10, 50); length > 0; length--) {
        // Choose if we generate a line or call a function.
        uint64 rand = randRange(0, 2);
        if (rand == 0) {
            LOG("Finding callable functions...")
            // Find all functions we can call.
            vector<function> callable;
            for (auto i = functions.cbegin(); i != functions.cend(); i++) {
                if(canCall(*i, variables) ) {
                    callable.push_back(*i);
                }
            }
            // Now we call one...
        
            if (callable.size() > 0) {
                LOG("Calling function...")
                function& func = callable[randRange(0, callable.size())];
                
                // Stores the arguments we will call the function with.
                vector<classDef::variable> funcArgs;
                
                // Go through all arguments and find variables to match them.
                for (auto i = func.getArgs().cbegin(); i != func.getArgs().cend(); i++) {
                    
                    // Holds all the variables we have that we can call it with.
                    vector<classDef::variable> possibleArgs;
                    for (auto j = variables.cbegin(); j != variables.cend(); j++) {
                        if (*i >= j->second) {
                            // Add the argument as a possible option.
                            possibleArgs.push_back(*j);
                        }
                    }
                    funcArgs.push_back(possibleArgs[randRange(0, possibleArgs.size() - 1) ]);
                }
                
                // Now that we found options, we can call the function.
                string functionCall;
                // Format the function name.
                functionCall += func.getName();
                functionCall += "(";
                for (auto i = funcArgs.begin(); i != funcArgs.end(); i++) {
                    // If it isn't the first variable, add a comma to separate the list.
                    if (i != funcArgs.begin()) {
                        functionCall += ", ";
                    }
                    // Add the variable name to call it with.
                    functionCall += i->first;
                    
                }
                functionCall += ");";
                
                // Call the function.
                CODE(functionCall)
                
            } else {
                LOG("No callable functions found. No code generated.")
            }

            
        } else if (rand == 1) {
            // Set a value
            LOG("Setting a variable...")
            
            
            
            
            
            
            
            
            
        } else {
            // Create a variable.
            LOG("Creating a variable...")
            
            // Determine variable type.
            classDef type = types[randRange(1, types.size() - 1)];
            
            // Determine variable name.
            string name = genName::get(type.getName(), variables);
            
            CODE(name << ";");
            variables.push_back(classDef::variable(name, type));
            LOG("Variable initialization failed - does not check constructors.")
            
        }
        
        // Currently, we won't implement smallScope.
    }
    
    // Finish function. Remove tab.
    logger::code_pre.pop_back();
    CODE("}")
    return ret;
}
