#include "logger.h"
#include <iostream>

logger::logger(std::string fname)
{
    output.open(fname);
}

logger::~logger()
{
    output.close();
}

template<typename T>
logger& logger::operator<< (T toLog)
{
    try {
        std::cout << toLog << std::endl;
        output << toLog << std::endl;
    } catch(std::exception e) {
        std::cout << "Error: Invalid print type. Type=" << typeid(T).name() << std::endl;
        std::cin.get();
        exit(-1);
    }
    
    return *this;
}