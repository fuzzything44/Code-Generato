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


int main(int32 len, char** args) {
    if (len != 3) {
        cout << "Invalid number of arguments." << endl;
        cout << "  Required arguments (in order): namefile-path outputfile-path length" << endl;
        cin.get();
        exit(-1);
    }
    
    string namePath = args[1];
    string outPath = args[0];
    int32 generateLength;
    cout << "Enter generation length: ";
    cin >> generateLength;
    
    logger::init(outPath);
    
    genName::init(namePath);
    {
        globalNamespace g;
        g.generate(generateLength);
    }
    logger::close();
}