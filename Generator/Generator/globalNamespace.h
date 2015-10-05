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
private:
    // Global namespace contains only functions and types. Not variables.
    std::vector<std::unique_ptr<function> > functions;
    std::vector<std::unique_ptr<classDef> > types;
};

#include "classScope.h"
#include "functionScope.h"
#include "smallScope.h"