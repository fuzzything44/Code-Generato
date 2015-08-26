#include "variableNamer.h"

using namespace std;

genName::genName(){
    preCheck = false;
    funcCheck = false;
    varCheck = false;
    
    varNum = 0;
    preNum = 0;
    funNum =0;
    
    vector <string> prefixLines;
    vector <string> funcLines;
    vector <string> varLines;

    ifstream infile;
    infile.open("names.txt");
    string lineInfo ;
    
    while(!infile.eof()){

        
        getline(infile,lineInfo);
        
        
        if( lineInfo == "-Prefix")
            preCheck = true;
        
        if(preCheck == true && lineInfo!="-Prefix"){
            preNum ++;
            prefixLines.push_back(lineInfo);
        }
        
        if( lineInfo == "-Func")
            funcCheck = true;
        
        if(preCheck == true && lineInfo!="-Func"){
            
            funNum ++;
            funcLines.push_back(lineInfo);
        }
        if( lineInfo == "-Var")
            varCheck = true;
        
        if(preCheck == true && lineInfo!="-Var"){
            
            varNum ++;
            varLines.push_back(lineInfo);
        }
        
        
        
    }
    infile.close();
    preCheck = false;
}

string genName::getFunc(){
    
    string nameTemp;
    nameTemp = prefixLines[randRange(0, preNum)] + funcLines[randRange(0, preNum)];

    
    return nameTemp;
}


string genName::getVar(){
    
    string nameTemp;
    nameTemp = prefixLines[randRange(0, preNum)] + varLines[randRange(0, preNum)];
    
    
    return nameTemp;
}





















