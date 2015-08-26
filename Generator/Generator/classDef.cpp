#include "classDef.h"
using std::string;
using std::vector;


classDef::classDef(string name, vector<classDef> parents, vector<function> funcs, vector<classDef> templateArguments) : name(name), parents(parents), funcs(funcs), templateArguments(templateArguments) {};

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

bool classDef::operator==(const classDef &isEqual) const
{
    // If the names are equal, they are the same class type.
    if (name == isEqual.name)
    {
        return true;
    } else {
        
        // Look for conversion operators.
        // Loop through all functions.
        for (vector<function>::const_iterator i = isEqual.funcs.begin(); i != isEqual.funcs.end(); i++)
        {
            // If the name is "operator CLASS", it is a proper conversion operator.
            if (i->getName() == ("operator " + name))
            {
                return true;
            }
        }
        
        
        // Look through all parents. If any parents work, they are the same class type.
        for (vector<classDef>::const_iterator i = isEqual.parents.begin(); i != isEqual.parents.end(); i++)
        {
            // Check the parent. *this == *i will call this function again on the parent.
            if ( *this == *i)
            {
                return true;
            }
        }
        
    }
    return false;
}

classDef& classDef::operator=(const classDef& set)
{
    name = set.name;
    parents = set.parents;
    funcs = set.funcs;
    templateArguments = set.templateArguments;
    return *this;
}
