#include "function.h"
#include "classDef.h"
#include "logger.h"
using std::string;
using std::vector;

function::function(std::string name, std::vector<const classDef*> args, const classDef* ret) : name(name), args(args), ret(ret)
{
    ENTER_FUNC("function::function(std::string name, std::vector<classDef> args, classDef ret)")
    LEAVE_FUNC_VOID("function::function(std::string name, std::vector<classDef> args, classDef ret)")
}

const vector<const classDef*>& function::getArgs() const
{
    ENTER_FUNC("function::getArgs()")
    LEAVE_FUNC("function::getArgs()", args)
}

const string& function::getName() const
{
    ENTER_FUNC("function::getName()")
    LEAVE_FUNC("function::getName()", name)
}

const classDef* function::getRet() const
{
    ENTER_FUNC("function::getRet()")
    LEAVE_FUNC("function::getRet()", ret)
}

bool function::operator==(const function& f) const
{
    ENTER_FUNC("function::operator==(const function& f)")
    LEAVE_FUNC("function::operator==(const function& f)", name == f.name)
}

function& function::operator=(const function& f)
{
    ENTER_FUNC("function::operator=(const function& f)")
    if(&f != this)
    {
        name = f.name;
        ret = f.ret;
        args = f.args;
    }
    LEAVE_FUNC("function::operator=(const function& f)", *this)
}

