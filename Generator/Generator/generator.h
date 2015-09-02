#pragma once

#include "classDef.h"
#include "function.h"
#include <vector>

class globalNamespace
{
public:
    globalNamespace();
    void generate(int length);
private:
    // Global namespace contains only functions and types. Not variables.
    std::vector<function> functions;
    std::vector<classDef> types;
};

class classScope
{
public:
    classScope(globalNamespace* parent);
    classDef generate();
    
private:
    std::vector<function> functions;
    std::vector<classDef> types;
    std::vector<std::pair<std::string, classDef> > variables;
};

class functionScope
{
public:
    functionScope(classScope* parent);
    functionScope(globalNamespace* parent);
    function generate();
    
private:
    std::vector<function> functions;
    std::vector<classDef> types;
    std::vector<std::pair<std::string, classDef> > variables;
};

class scope
{
    
};