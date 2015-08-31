#include "logger.h"

std::ofstream logger::log;
std::ofstream logger::code;

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
