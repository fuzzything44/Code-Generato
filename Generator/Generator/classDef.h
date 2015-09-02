#pragma once
#include <vector>
#include <string>

// We know functions exist.
class function;

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
    
    // Function to add functions
    void addFunction(function f);
    
    // Operators
    
    //If returns true if isEqual is a subclass, equal to, or has a conversion operator to this or a subclass of this.
    bool operator>=(const classDef& isEqual) const;
    // Operates pretty much the same as >=, just the other way around.
    bool operator<=(const classDef& isEqual) const;
    // Class types must be the same and template arguments must be equal.
    bool operator==(const classDef& isEqual) const;
    bool operator!=(const classDef& isEqual) const;
    classDef& operator=(const classDef& set);
private:
    std::string name;
    std::vector<function> funcs;
    std::vector<classDef> parents;
    std::vector<classDef> templateArguments;
};

// Now we can know what a function is.
#include "function.h"