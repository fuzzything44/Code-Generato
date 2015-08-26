#pragma once
#include <fstream>
#include <string>

class logger
{
    std::ofstream output;
public:
    logger(std::string fname);
    ~logger();
    
    template<typename T> logger& operator<< (T toLog);
};
