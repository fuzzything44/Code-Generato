#pragma once

#include "globalNamespace.h"
#include "classScope.h"
#include "smallScope.h"
#include "function.h"
#include "classDef.h"
#include <vector>

class functionScope
{
public:
    friend smallScope;
    
    functionScope(classScope* parent);
    functionScope(globalNamespace* parent);
    function generate();
    
private:
    std::vector<function> functions;
    std::vector<classDef> types;
    std::vector<classDef::variable > variables;
};
