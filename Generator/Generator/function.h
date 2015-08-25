#pragma once
#include <string>
#include <vector>

class function
{
public:
    function(std::string name, std::vector<std::string>& templateArgs, std::vector<std::string>& args, std::string ret);
    
    // Returns function name
    std::string getName();
    
    // Returns template arguments.
    std::vector<std::string> getTemplateArgs();
    
    // Returns function arguments. Vector holds types, not names.
    std::vector<std::string> getArgs();
    
    // Returns return type
    std::string getRet();
    
private:
    std::string name;
    std::vector<std::string> templateArgs;
    std::vector<std::string> args;
    std::string ret;
    
};
