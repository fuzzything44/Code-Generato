#include "logger.h"

void logger::init(std::string fname)
{
    logger::code.open(fname + "_code");
    logger::log.open(fname + "_log");
}

void logger::close()
{
    logger::code.close();
    logger::log.close();
}
