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

bool classDef::operator<=(const classDef& isEqual) const
{
    return isEqual >= *this;
}

bool classDef::operator==(const classDef& isEqual) const
{
    /*
     
     DOES NOT WORK!!! vectors may not check each individual element!!!!!!!!!
     
     
     
     
     
     
     
     
     
     
     
     
     */
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
            // THIS NEEDS CHANGING. CHECK OPERATOR RETURN TYPE!!!!!!!!!!!!!!!!!!!!!
            /*
             
             
             Space so I notice this
             
             
             
             
             
             
             
             
             
             
             
             
             */
            // If the name is "operator CLASS", it is a proper conversion operator.
            if (i->getName() == ("operator " + name))
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
