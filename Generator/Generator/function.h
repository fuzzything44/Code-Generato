#pragma once
#include <string>
#include <vector>

class function
{
public:
    function(std::string name, std::vector<std::string>& args, std::string ret);
    
    // Returns function name
    std::string name();
    
    // Returns function arguments. Vector holds types, not names. 
    std::vector<string> args();
};
