#include "classDef.h"
#include "logger.h"
using std::string;
using std::vector;


classDef::classDef(const string& name) : name(name) {};

vector<function> classDef::getFuncs() const
{
    return funcs;
}
const vector<function>& classDef::cgetFuncs() const
{
    return funcs;
}

string classDef::getName() const
{
    return name;
}
const string& classDef::cgetName() const
{
    return name;
}

vector<classDef::variable> classDef::getVars() const
{
    return vars;
}
const vector<classDef::variable>& classDef::cgetVars() const
{
    return vars;
}


void classDef::addFunction(const function& f)
{
    funcs.push_back(f);
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
    
    LOG("  Checking the names...")
    // If the names are equal, they are the same class type.
    if (name == isEqual.getName() )
    {
        LOG(" Returning true")
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
                        
                        LOG(" Returning true")
                        return true;
                    }
                    hasCalled = false;
                }
            }
        }
    } // End else
    LOG(" Returning false")
    return false;
}

classDef& classDef::operator=(const classDef& set)
{
    if (&set != this)
    {
        name = set.name;
        funcs = set.funcs;
    }
    return *this;
}
