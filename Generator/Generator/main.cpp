#include "stdafx.h"
#include <iostream>
#include "genName.h"
#include "logger.h"
#include "globalNamespace.h"

using std::cout;
using std::string; 
using std::cin;
using std::endl;

#define TEST_CODE_GEN


int main() {
    
    logger::init("Name generator");
    genName::init();
    
#ifdef TEST_NAME_GEN
    while (true) {
        string s;
        cin >> s;
        cout << genName::get(s) << endl;
        
    }
#else
    globalNamespace g;
    g.generate(5);
#endif
    
    logger::close();
}
