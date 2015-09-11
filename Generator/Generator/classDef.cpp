#include "classDef.h"
using std::string;
using std::vector;


classDef::classDef(string name) : name(name) {};

vector<function> classDef::getFuncs() const
{
    return funcs;
}

string classDef::getName() const
{
    return name;
}

vector<classDef> classDef::getParents() const
{
    return parents;
}

vector<classDef> classDef::getTemplateArgs() const
{
    return templateArguments;
}

void classDef::addFunction(function f)
{
    funcs.push_back(f);
}

void classDef::addParent(classDef p)
{
    parents.push_back(p);
}

void classDef::addVar(std::pair<std::string, classDef> v)
{
    vars.push_back(v);
}

bool classDef::operator<=(const classDef& isEqual) const
{
    return isEqual >= *this;
}

bool classDef::operator==(const classDef& isEqual) const
{
    return name == isEqual.name && templateArguments == isEqual.getTemplateArgs();
}

bool classDef::operator!=(const classDef& isEqual) const
{
    return !(*this == isEqual);
}

bool classDef::operator>=(const classDef &isEqual) const
{
    // Template arguments must be the same. ALWAYS!!!!!
    if (templateArguments.size() != isEqual.getTemplateArgs().size())
    {
        return false;
    } else {
        // Checking all template arguments.
        vector<classDef>::const_iterator equal = isEqual.getTemplateArgs().begin();
        for (vector<classDef>::const_iterator current = templateArguments.begin(); current != templateArguments.begin(); current++)
        {
            if( *equal != *current)
            {
                return false;
            }
            equal++;
        }
    }
    // Template arguments should be the same now.
    
    // If the names are equal, they are the same class type.
    if (name == isEqual.getName() )
    {
        return true;
    } else {
        
        // Look for conversion operators.
        // Loop through all functions.
        for (vector<function>::const_iterator i = isEqual.getFuncs().begin(); i != isEqual.getFuncs().end(); i++)
        {
            // If a function is an operator and returns a type that is a subclass or the same, it works.
            if (i->getName().substr(0, 8) == ("operator") && *this >= i->getRet())
            {
                return true;
            }
        }
        
        
        // Look through all parents. If any parents work, they are the same class type.
        for (vector<classDef>::const_iterator i = isEqual.getParents().begin(); i != isEqual.getParents().end(); i++)
        {
            // Check the parent. *this == *i will call this function again on the parent.
            if ( *this >= *i)
            {
                return true;
            }
        }
        
    }
    return false;
}

classDef& classDef::operator=(const classDef& set)
{
    if (&set != this)
    {
        name = set.name;
        parents = set.parents;
        funcs = set.funcs;
        templateArguments = set.templateArguments;
    }
    return *this;
}
