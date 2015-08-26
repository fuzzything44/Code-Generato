#pragma once
#include <string>
#include <vector>

// We need to know templateArgument is a class. We don't need to know what it does.
class classDef;

class function
{
public:
    function(std::string name, std::vector<classDef>& templateArgs, std::vector<classDef>& args, std::string ret);
    
    // Returns function name
    std::string getName() const;
    
    // Returns template arguments.
    std::vector<classDef> getTemplateArgs() const;
    
    // Returns function arguments. Vector holds types, not names.
    std::vector<classDef> getArgs() const;
    
    // Returns return type
    std::string getRet() const;
    
private:
    std::string name;
    std::vector<classDef> templateArgs;
    std::vector<classDef> args;
    std::string ret;
    
};

