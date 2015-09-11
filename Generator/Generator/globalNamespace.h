#pragma once

#include "classDef.h"
#include "function.h"
#include <vector>

class classScope;
class functionScope;
class smallScope;

class globalNamespace
{
public:
    friend classScope;
    friend functionScope;
    
    globalNamespace();
    void generate(int length);
private:
    // Global namespace contains only functions and types. Not variables.
    std::vector<function> functions;
    std::vector<classDef> types;
};

#include "classScope.h"
#include "functionScope.h"
#include "smallScope.h"