#pragma once

#include "globalNamespace.h"
#include "classDef.h"

#include <vector>

class classScope
{
public:
    friend functionScope;
    
    classScope(globalNamespace* parent);
    classDef generate();
    
private:
    std::vector<function> functions;
    std::vector<classDef> types;
    std::vector<classDef::variable > variables;
};