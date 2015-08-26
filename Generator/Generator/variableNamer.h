#pragma once
#include"iostream"
#include"random.h"
#include"fstream"
#include"string"

class genName{
public:
    genName();
    
    std::string getVar();
    std:: string getFunc();
    ~genName();
    
private:
    std::string poop;
    std::vector <std::string> prefixLines;
    std::vector <std::string> funcLines;
    std::vector <std::string> varLines;
    bool preCheck;
    bool funcCheck;
    bool varCheck;
    int varNum;
    int funNum;
    int preNum;
};