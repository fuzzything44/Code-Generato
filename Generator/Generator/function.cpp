#include "function.h"
#include "classDef.h"
#include "logger.h"
using std::string;
using std::vector;

function::function(std::string name, std::vector<classDef> args, classDef ret) : name(name), args(args), ret(ret) {}

const vector<classDef>& function::getArgs() const
{
    return args;
}

const string& function::getName() const
{
    
    return name;
}

const classDef& function::getRet() const
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

