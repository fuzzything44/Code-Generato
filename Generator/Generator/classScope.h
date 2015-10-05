#pragma once
#include "stdafx.h"
#include "globalNamespace.h"
#include "classDef.h"

#include <vector>

class classScope
{
public:
    friend functionScope;
    
    classScope(globalNamespace* parent);
    classDef* generate();
    
    classDef* get_random_type();
    function* get_random_func();
    classDef::variable get_random_var();
    
private:
    std::vector<std::unique_ptr<classDef> >* types;
    std::vector<std::unique_ptr<function> >* parentFuncs;
    std::vector<function*> functions;
    std::vector<classDef::variable> variables;
};