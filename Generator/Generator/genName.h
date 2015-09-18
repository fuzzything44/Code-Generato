#pragma once
#include "stdafx.h"
#include "iostream"
#include "random.h"
#include "fstream"
#include "string"
#include <map>
#include "classDef.h"

class genName{
public:
    static void init();
    static std::string get(std::string type, std::vector<classDef::variable> v);

private:
    static std::map<std::string, std::vector<std::string> > lines;
};