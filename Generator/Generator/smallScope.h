#pragma once
#include "stdafx.h"
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
    std::vector<const classDef*> types;
    std::vector<const function*> functions;
    std::vector<classDef::variable> vars;
};