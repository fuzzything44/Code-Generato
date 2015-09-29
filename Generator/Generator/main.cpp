#include "stdafx.h"
#include <iostream>
#include "genName.h"
#include "logger.h"
#include "globalNamespace.h"

using std::cout;
using std::string; 
using std::cin;
using std::endl;

//#define TEST_NAME_GEN


int main() {
    
    logger::init("Name generator");
    genName::init();
    
#ifdef TEST_NAME_GEN
    while (true) {
        cout << "Enter name type: ";
        string s;
        cin >> s;
        cout << genName::get(s) << endl;
    }
#else
    globalNamespace g;
    g.generate(1);
#endif
    
    logger::close();
}
