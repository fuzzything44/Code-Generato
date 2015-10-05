#pragma once
#include "stdafx.h"
#include <vector>
#include <string>

// We know functions exist.
class function;

// Defines what a class is

class classDef
{
public:
    typedef pair_type<std::string, classDef*> variable;
    
    classDef(const std::string& name);
    // Getter functions
    const std::vector<const function*>& getFuncs() const;
    const std::string& getName() const;
    const std::vector<variable>& getVars() const;
    
    // Function to add functions
    void addFunction(const function& f);
    void addVar(const variable& v);

    
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
    std::vector<const function*> funcs;
    std::vector<variable> vars;
};

// Now we can know what a function is.
#include "function.h"