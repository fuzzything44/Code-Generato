#pragma once
#include "stdafx.h"
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
    const function* generate();
    
private:
    std::vector<const function*> functions;
    std::vector<const classDef*> types;
    std::vector<classDef::variable > variables;
};
