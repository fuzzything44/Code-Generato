#include "function.h"
using std::string;
using std::vector;

function::function(std::string name, std::vector<std::string>& templateArgs, std::vector<std::string>& args, std::string ret) : name(name), templateArgs(templateArgs), args(args), ret(ret) {}

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

vector<string> function::getTemplateArgs() const
{
    return templateArgs;
}

bool function::isCalledCorrectly(const string& call) const
{
    string::size_type iter;
    string parse;
    
    // Parsing out the name.
    while (call[iter] != '<' && call[iter] != '(' )
    {
        parse += call[iter];
        iter++;
    }
    
    // Checking that names are equal.
    if (parse != name)
    {
        return false;
    }
    parse.clear();
    
    // If there are template arguments...
    if (iter == '<')
    {
        vector<string> tempArgs;
        
        // > signifies end of template arguments.
        while (iter != '>')
        {
            iter++;
            // Find the end of the argument.
            while (iter != ',' && iter != '>')
            {
                parse += call[iter];
            }
            tempArgs.push_back(parse);
        }
        
        // At this point all template args should be in the vector.
    }
    
    return true;
}

