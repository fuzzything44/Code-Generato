#include "function.h"
#include "classDef.h"
#include "logger.h"
using std::string;
using std::vector;

function::function(std::string name, std::vector<classDef> args, classDef ret) : name(name), args(args), ret(ret) {}

vector<classDef> function::getArgs() const
{
    return args;
}
const vector<classDef>& function::cgetArgs() const
{
    return args;
}


string function::getName() const
{

    return name;
}
const string& function::cgetName() const
{
    
    return name;
}

classDef function::getRet() const
{
    return ret;
}
const classDef& function::cgetRet() const
{
    return ret;
}

bool function::operator==(const function& f) const
{
    return name == f.name;
}

function& function::operator=(const function& f)
{
    if(&f != this)
    {
        name = f.getName();
        ret = f.getRet();
        args = f.getArgs();
    }
    return *this;
}

