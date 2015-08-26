#pragma once
#include"iostream"
#include"random.h"
#include"fstream"
#include"string"

class genName{
public:
    genName();
    
    std::string getVar();
    std::string getFunc();
    std::string getConst();
    ~genName();
    
private:
    std::string lienInfo;
    
    std::vector <std::string> prefixLines;
    std::vector <std::string> funcLines;
    std::vector <std::string> varLines;
    std::vector <std::string> constLines;

    
    std::vector <std::string> usedNames;

    bool preCheck;
    bool funcCheck;
    bool varCheck;
    bool constCheck;
    
    
    int varNum;
    int funNum;
    int preNum;
    int constNum;
    
    int numNames;
    
};