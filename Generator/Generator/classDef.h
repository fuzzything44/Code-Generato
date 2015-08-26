#pragma once
#include "function.h"
#include <vector>
#include <string>

// Defines what a class is

class classDef
{
public:
    classDef(std::string name, std::vector<classDef> parents, std::vector<function> funcs, std::vector<classDef> templateArguments);
    
    // Getter functions
    std::vector<function> getFuncs() const;
    std::string getName() const;
    std::vector<classDef> getParents() const;
    std::vector<classDef> getTemplateArgs() const;
    
    // Operators
    
    // If b is a subclass of a, a == b but b != a
    bool operator==(const classDef& isEqual) const;
    classDef& operator=(const classDef& set);
private:
    std::string name;
    std::vector<function> funcs;
    std::vector<classDef> parents;
    std::vector<classDef> templateArguments;
};