#include "function.h"
using std::string;
using std::vector;

function::function(std::string name, std::vector<templateArgument>& templateArgs, std::vector<std::string>& args, std::string ret) : name(name), templateArgs(templateArgs), args(args), ret(ret) {}

vector<string> function::getArgs() const
{
    return args;
}

string function::getName() const
{
    return name;
}

string function::getRet() const
{
    return ret;
}

vector<templateArgument> function::getTemplateArgs() const
{
    return templateArgs;
}

