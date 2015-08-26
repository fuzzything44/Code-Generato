#pragma once
#include <fstream>
#include <string>

class logger
{
    std::ofstream code;
    std::ofstream log;
    bool isLogging;
public:
    logger(std::string fname);
    ~logger();
    
    // Sets if it logs the statement or counts it as code. true = log, false = code.
    void setLogging(bool state);
    
    template<typename T> logger& operator<< (T toLog);
};
