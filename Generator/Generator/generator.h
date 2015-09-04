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

class classScope
{
public:
    friend functionScope;
    
    classScope(globalNamespace* parent);
    classDef generate();
    
private:
    std::vector<function> functions;
    std::vector<classDef> types;
    std::vector<classDef::variable > variables;
};

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


// For for loops, while loops, if statements, etc.
class smallScope
{
public:
    smallScope(functionScope* parent);
    void generate();

private:
    std::vector<function> functions;
    std::vector<classDef> types;
    std::vector<classDef::variable > variables;
};