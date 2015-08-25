#pragma once
#include <string>
#include <vector>

class function
{
public:
    function(std::string name, std::vector<std::string>& templateArgs, std::vector<std::string>& args, std::string ret);
    
    // Returns function name
    std::string getName() const;
    
    // Returns template arguments.
    std::vector<std::string> getTemplateArgs() const;
    
    // Returns function arguments. Vector holds types, not names.
    std::vector<std::string> getArgs() const;
    
    // Returns return type
    std::string getRet() const;
    
    bool isCalledCorrectly(const std::string& call) const;
    
private:
    std::string name;
    std::vector<std::string> templateArgs;
    std::vector<std::string> args;
    std::string ret;
    
};
