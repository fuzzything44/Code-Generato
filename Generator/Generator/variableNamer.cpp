#include "variableNamer.h"

using namespace std;

genName::genName(){
    preCheck = false;
    otherCheck = false;
    int varNum = 0;
    vector <string> name;
    vector <string> name2;
    
    ifstream infile;
    infile.open("names.txt");
    string poop ;
    
    while(!infile.eof()){

        
        getline(infile,poop);
        
        
        if( poop == "-Prefix")
            preCheck = true;
        
        if(preCheck == true && poop!="-Prefix"){
            
            name.push_back(poop);
    }
        
        if( poop == "-Other")
            otherCheck = true;
        
        if(preCheck == true && poop!="-Other"){
            
            varNum ++;
            name2.push_back(poop);
        }
        
        
        
    }
    infile.close();
    preCheck = false;
}

string genName::getFunc(){
    
    string name;
    randRange(1, 1);
    
    
    
    
    return name;
}