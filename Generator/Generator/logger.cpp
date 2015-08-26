#include "logger.h"
#include <iostream>

logger::logger(std::string fname)
{
    code.open(fname + "_code");
    log.open(fname + "_log");
}

logger::~logger()
{
    code.close();
    log.close();
}

void logger::setLogging(bool state)
{
    isLogging = state;
}

template<typename T>
logger& logger::operator<< (T toLog)
{
    
    try {
        // If it is logging, say so. If not, put an indent in.
        if (isLogging)
        {
            std::cout << "LOG: ";
        } else {
            std::cout << "\t";
        }
        
        // Print the message.
        std::cout << toLog << std::endl;
        // Log to the correct stream.
        (isLogging ? log : code) << toLog << std::endl;
        
    } catch(std::exception e) {
        // If something goes wrong (invalid type given), say so, give the type, wait and crash.
        std::cout << "Error: Print Type = " << typeid(T).name() << std::endl;
        std::cout << "Error: Error type: " << e.what() << std::endl;
        std::cin.get();
        exit(-1);
    }
    
    return *this;
}