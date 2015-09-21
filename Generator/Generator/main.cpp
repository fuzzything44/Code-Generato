#include "stdafx.h"
#include <iostream>
#include "genName.h"
#include "logger.h"
#include "globalNamespace.h"

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main() {
    
    logger::init("Name generator");
    genName::init();
    
    std::vector<classDef::variable> v;
    for (int i = 0; i < 50; i++) {
        cout << genName::get("typename", v) << endl;
    }
    

        
 //   globalNamespace g;
 //   g.generate(3);
    
    logger::close();
}
