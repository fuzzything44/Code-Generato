#include "logger.h"
#include <iostream>

std::ofstream logger::log;
std::ofstream logger::code;
std::string code_pre = "";

void logger::init(std::string fname)
{
    if (logger::code.is_open()) {
        logger::code.close();
    }
    if (logger::log.is_open()) {
        logger::log.close();
    }
    logger::code.open(fname + "_code");
    logger::log.open(fname + "_log");
    logger::code_pre = "";
    logger::line = 1;
    std::cout << "Opened log with name=" << fname << std::endl;
}

void logger::close()
{
    logger::log << "Closing log..." << std::endl;
    std::cout << "Closing log and code output." << std::endl;
    logger::code.close();
    logger::log.close();
}
