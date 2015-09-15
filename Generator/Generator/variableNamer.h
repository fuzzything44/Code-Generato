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


private:
    static std::map<std::string, std::vector<std::string> > lines;
<<<<<<< Updated upstream
=======
  

>>>>>>> Stashed changes
};