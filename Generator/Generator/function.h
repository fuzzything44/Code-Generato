#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
#include "classDef.h"

class function
{
public:
    function(std::string name, std::vector<classDef> args, classDef ret );
    
    // Returns function name
    std::string getName() const;
    const std::string& cgetName() const;
    
    // Returns function arguments. Vector holds types, not names.
    std::vector<classDef> getArgs() const;
    const std::vector<classDef>& cgetArgs() const;
    
    // Returns return type
    classDef getRet() const;
    const classDef& cgetRet() const;
    
    // Operators.
    bool operator==(const function& f) const;
    function& operator=(const function& f);
private:
    std::string name;
    std::vector<classDef> args;
    classDef ret;
    
};


