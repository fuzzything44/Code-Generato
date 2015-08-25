#include "function.h"
using std::string;
using std::vector;

function::function(std::string name, std::vector<std::string>& templateArgs, std::vector<std::string>& args, std::string ret) : name(name), templateArgs(templateArgs), args(args), ret(ret) {}

vector<string> function::getArgs()
{
    return args;
}

string function::getName()
{
    return name;
}

string function::getRet()
{
    return ret;
}

vector<string> function::getTemplateArgs()
{
    return templateArgs;
}