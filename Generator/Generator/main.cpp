#include <iostream>
#include "variableNamer.h"
using namespace std;

int main(int argc, const char * argv[]) {
    genName g;
    while (true)
    {
        string type;
        cin >> type;
        if (type == "var" )
            cout << g.getVar() << endl;
        if (type == "const")
            cout << g.getConst() << endl;
        if (type == "func")
            cout << g.getFunc() << endl;
    }
}
