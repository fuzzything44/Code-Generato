#pragma once
#include "iostream"
#include "random.h"
#include "fstream"
#include "string"
#include <map>

class genName{
public:
    static void init();
    static std::string get(std::string type);
    static std::string getVar();
    static std::string getFunc();
    static std::string getConst();

private:
    static std::map<std::string, std::vector<std::string> > lines;
    static std::vector<std::string> prefixLines;
    static std::vector<std::string> funcLines;
    static std::vector<std::string> varLines;
    static std::vector<std::string> constLines;
    static std::vector<std::string> usedNames;
};