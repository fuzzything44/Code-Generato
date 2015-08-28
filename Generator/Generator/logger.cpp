#include "logger.h"
#include <iostream>

void logger::init(std::string fname)
{
    code.open(fname + "_code");
    log.open(fname + "_log");
}

void logger::close()
{
    code.close();
    log.close();
}
