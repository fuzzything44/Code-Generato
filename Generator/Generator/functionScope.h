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
    function* generate();
    
    classDef* get_random_type();
    function* get_random_func();
    classDef::variable get_random_var();

private:
    std::vector<std::unique_ptr<function> >* functions;
    std::vector<function*>* classFuncs;
    std::vector<std::unique_ptr<classDef> >* types;
    std::vector<classDef::variable> variables;
    std::vector<classDef::variable>* parentVars;
};
