#include <iostream>
#include "variableNamer.h"
#include "logger.h"
using namespace std;

int main() {
    logger::init("TEST");
    if(logger::log.is_open()) {
        LOG("ABCD")
    } else { cout << "FAILED!!! LOG IS NOT OPEN!!!" << endl; }
    logger::close();
    
    
    exit(0);
    genName g;
    while (true)
    {
        cout << "What type? var const func" << endl;
        string type;
        cin >> type;
        if (type == "var" )
            cout << g.getVar() << endl;
        if (type == "const")
            cout << g.getConst() << endl;
        if (type == "func")
            cout << g.getFunc() << endl;
        if (type == "end")
            return 0;
    }
}
