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
    
        
    globalNamespace g;
    g.generate(3);
    
    logger::close();
}
