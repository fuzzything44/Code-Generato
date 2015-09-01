#include "function.h"
#include "classDef.h"
using std::string;
using std::vector;

function::function(std::string name, std::vector<classDef>& templateArgs, std::vector<classDef>& args, classDef ret) : name(name), templateArgs(templateArgs), args(args), ret(ret) {}

vector<classDef> function::getArgs() const
{
    return args;
}

string function::getName() const
{
    return name;
}

classDef function::getRet() const
{
    return ret;
}

vector<classDef> function::getTemplateArgs() const
{
    return templateArgs;
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
        templateArgs = f.getTemplateArgs();
        args = f.getArgs();
    }
    return *this;
}

