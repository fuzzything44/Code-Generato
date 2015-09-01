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

