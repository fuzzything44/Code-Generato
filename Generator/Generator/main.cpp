#include <iostream>
#include "variableNamer.h"
#include "logger.h"
using namespace std;

int main() {
    
    logger::init("TEST");
    genName g;
    while (true)
    {
        cout << "What type? var const func" << endl;
        string type;
        cin >> type;
        if (type == "var" )
        {
            LOG("Getting variable name...")
            CODE(g.getVar())
        } else if (type == "const")
        {
            LOG("Getting const name...")
            CODE(g.getConst())
        } else if (type == "func")
        {
            LOG("Getting function name...")
            CODE(g.getFunc())
        } else if (type == "end")
        {
            break;
        }
    }
    logger::close();
}
