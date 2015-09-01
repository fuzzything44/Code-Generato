#pragma once
#include <string>
#include <vector>
#include "classDef.h"

class function
{
public:
    function(std::string name, std::vector<classDef>& templateArgs, std::vector<classDef>& args, classDef ret);
    
    // Returns function name
    std::string getName() const;
    
    // Returns template arguments.
    std::vector<classDef> getTemplateArgs() const;
    
    // Returns function arguments. Vector holds types, not names.
    std::vector<classDef> getArgs() const;
    
    // Returns return type
    classDef getRet() const;
    
private:
    std::string name;
    std::vector<classDef> templateArgs;
    std::vector<classDef> args;
    classDef ret;
    
};


