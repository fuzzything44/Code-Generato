#include "stdafx.h"
#include <iostream>
#include "genName.h"
#include "logger.h"
#include "globalNamespace.h"
#include <typeinfo>

using std::cout;
using std::string; 
using std::cin;
using std::endl;


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
    int length;
    cout << "How much code to generate?" << endl;
    cin >> length;
    if (length > 10) {
        cout << "That's too long. 1 to 10 please." << endl;
        length = 10;
    } else if (length <= 0) {
        cout << "Please actually ask to generate code. 10 to 10 please." << endl;
        exit(0);
    }
    g.generate(length);
#endif
    
    logger::close();
}