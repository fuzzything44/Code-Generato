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
    typedef std::pair<std::string, classDef> variable;
    
    classDef(const std::string& name);
    // Getter functions
    std::vector<function> getFuncs() const;
    std::string getName() const;
    std::vector<classDef> getParents() const;
    std::vector<classDef> getTemplateArgs() const;
    std::vector<variable> getVars();
    
    // Function to add functions
    void addFunction(const function& f);
    void addVar(const variable& v);
    void addParent(const classDef& p);
    
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
    std::vector<variable> vars;
};

// Now we can know what a function is.
#include "function.h"