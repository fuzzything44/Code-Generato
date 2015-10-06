#pragma once
#include "stdafx.h"
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
    void generate(int32 length);
    virtual ~globalNamespace();
    
private:
    // Global namespace contains only functions and types. Not variables.
    std::vector<const function*> functions;
    std::vector<const classDef*> types;
    std::vector<destroyer*> death;
};

#include "classScope.h"
#include "functionScope.h"
#include "smallScope.h"