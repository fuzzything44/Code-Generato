#pragma once
#include <string>
#include <vector>

// We need to know templateArgument is a class. We don't need to know what it does.
class templateArgument;

class function
{
public:
    function(std::string name, std::vector<templateArgument>& templateArgs, std::vector<std::string>& args, std::string ret);
    
    // Returns function name
    std::string getName() const;
    
    // Returns template arguments.
    std::vector<templateArgument> getTemplateArgs() const;
    
    // Returns function arguments. Vector holds types, not names.
    std::vector<std::string> getArgs() const;
    
    // Returns return type
    std::string getRet() const;
    
private:
    std::string name;
    std::vector<templateArgument> templateArgs;
    std::vector<std::string> args;
    std::string ret;
    
};

// Now we can learn what templateArgument is.
#include "templateArgument.h"
