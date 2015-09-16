#include "stdafx.h"
#include <iostream>
#include "genName.h"
#include "logger.h"
using std::cout;
using std::string;
using std::cin;
using std::endl;

int main() {
    
    logger::init("TEST");
    genName::init();
    
    while (true)
    {
        cout << "What type?" << endl;
        string type;
        cin >> type;
        CODE(genName::get(string("-") + type) );
    }
    logger::close();
}
