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
    std::vector <std::string> name;
    std::vector <std::string> name2;
    bool preCheck;
    bool otherCheck;
    int varNum;
    int funNum;
};