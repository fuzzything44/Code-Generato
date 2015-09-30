#include "classDef.h"
#include "logger.h"
using std::string;
using std::vector;


classDef::classDef(const string& name) : name(name) {};

const vector<function>& classDef::getFuncs() const
{
    ENTER_FUNC("classDef::getFuncs()")
    LEAVE_FUNC("classDef::getFuncs()", funcs)

}

const string& classDef::getName() const
{
    ENTER_FUNC("classDef::getName()")
    LEAVE_FUNC("classDef::getName()", name)
}

const vector<classDef::variable>& classDef::getVars() const
{
    ENTER_FUNC("classDef::getName()")
    LEAVE_FUNC("classDef::getName()", vars)
}


void classDef::addFunction(const function& f)
{
    ENTER_FUNC("classDef::addFunction(const function& f)")
    funcs.push_back(f);
    LEAVE_FUNC_VOID("classDef::addFunction(const function& f)")
}

void classDef::addVar(const variable& v)
{
    ENTER_FUNC("classDef::addVar(const variable& v)")
    vars.push_back(v);
    LEAVE_FUNC_VOID("classDef::addVar(const variable& v)")
}

bool classDef::operator<=(const classDef& isEqual) const
{
    ENTER_FUNC("classDef::operator<=(const classDef& isEqual)")
    bool ret = isEqual >= *this;
    LEAVE_FUNC("classDef::operator<=(const classDef& isEqual)", ret)
}

bool classDef::operator==(const classDef& isEqual) const
{
    ENTER_FUNC("classDef::operator==(const classDef& isEqual")
    LEAVE_FUNC("classDef::operator==(const classDef& isEqual)", name == isEqual.getName())
}

bool classDef::operator!=(const classDef& isEqual) const
{
    ENTER_FUNC("classDef::operator!=(const classDef& isEqual)")
    LEAVE_FUNC("classDef::operator!=(const classDef& isEqual)",!(*this == isEqual) )
}

bool classDef::operator>=(const classDef &isEqual) const
{
    ENTER_FUNC("classDef::operator>=(const classDef &isEqual)")
    LOG("Checking >= on class " << name << " and " << isEqual.getName() )
    static bool hasCalled = false;
    
    LOG("  Checking the names...")
    // If the names are equal, they are the same class type.
    if (name == isEqual.getName() )
    {
        LOG(" Returning true")
        LEAVE_FUNC("classDef::operator>=(const classDef &isEqual)", true)
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
                        LEAVE_FUNC("classDef::operator>=(const classDef &isEqual)", true)
                    }
                    hasCalled = false;
                }
            }
        }
    } // End else
    LEAVE_FUNC("classDef::operator>=(const classDef &isEqual)", false)
}

classDef& classDef::operator=(const classDef& set)
{
    ENTER_FUNC("classDef::operator=(const classDef& set)")
    if (&set != this)
    {
        name = set.name;
        funcs = set.funcs;
    }
    LEAVE_FUNC("classDef::operator=(const classDef& set)", *this)
}
