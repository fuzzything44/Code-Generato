#pragma once

#include "functionScope.h"
#include <vector>
#include "classDef.h"
// For while loops, if blocks, etc.
class smallScope
{
public:
    smallScope(functionScope* parent);
    void generate();
    
private:
    std::vector<classDef> types;
    std::vector<function> functions;
    std::vector<classDef::variable> vars;
};