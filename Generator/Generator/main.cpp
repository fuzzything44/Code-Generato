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
    genName g;
    while (true)
    {
        cout << "What type? var const func" << endl;
        string type;
        cin >> type;
        if (type == "var" )
        {
            LOG("Getting variable name...")
            CODE(g.get("-Var"))
        } else if (type == "const")
        {
            LOG("Getting const name...")
            CODE(g.get("-Const"))
        } else if (type == "func")
        {
            LOG("Getting function name...")
            CODE(g.get("-Func"))
        } else if (type == "end")
        {
            break;
        }
    }
    logger::close();
}
