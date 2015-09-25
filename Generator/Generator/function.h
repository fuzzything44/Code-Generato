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
    const std::string& getName() const;
    
    // Returns function arguments. Vector holds types, not names.
    const std::vector<classDef>& getArgs() const;
    
    // Returns return type
    const classDef& getRet() const;
    
    // Operators.
    bool operator==(const function& f) const;
    function& operator=(const function& f);
private:
    std::string name;
    std::vector<classDef> args;
    classDef ret;
    
};


