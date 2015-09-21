#include "classDef.h"
#include "logger.h"
using std::string;
using std::vector;


classDef::classDef(const string& name) : name(name) {};

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

void classDef::addFunction(const function& f)
{
    funcs.push_back(f);
}

void classDef::addParent(const classDef& p)
{
    parents.push_back(p);
}

void classDef::addVar(const variable& v)
{
    vars.push_back(v);
}

bool classDef::operator<=(const classDef& isEqual) const
{
    return isEqual >= *this;
}

bool classDef::operator==(const classDef& isEqual) const
{
    return name == isEqual.name;
}

bool classDef::operator!=(const classDef& isEqual) const
{
    return !(*this == isEqual);
}

bool classDef::operator>=(const classDef &isEqual) const
{
    LOG("Checking >= on class " << this->name << " and " << isEqual.name)
    static bool hasCalled = false;
    
    LOG("  Checking template arguments...")
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
    
    LOG("  Checking the names...")
    // If the names are equal, they are the same class type.
    if (name == isEqual.getName() )
    {
        return true;
    } else {
        LOG("  Checking conversion operators...")
        // Look for conversion operators.
        // Loop through all functions if we aren't already with a conversion operator.
        if (!hasCalled) {
            for (vector<function>::const_iterator i = isEqual.getFuncs().begin(); i != isEqual.getFuncs().end(); i++)
            {
                // If a function is an operator and returns a type that is a subclass or the same, it works.
                if (i->getName().substr(0, 8) == ("operator") && *this >= i->getRet())
                {
                    hasCalled = true;
                    if ( *this >= i->getRet() ) {
                        LOG("    Found conversion operator. Checking converted class...")
                        hasCalled = false;
                        return true;
                    }
                    hasCalled = false;
                }
            }
        }
        
        LOG("  Checking parents...")
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
