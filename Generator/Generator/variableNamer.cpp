#include "variableNamer.h"
#include "logger.h"

using namespace std;

genName::genName() {
    numNames =0;
    
    //Check Vars
    preCheck = false;
    funcCheck = false;
    varCheck = false;
    constCheck =false;
    
    //Number of names
    varNum = 0;
    preNum = 0;
    funNum = 0;
    constNum = 0;
    //Store Lines Info
    prefixLines.push_back("");
    funcLines.push_back("");
    varLines.push_back("");
    constLines.push_back("");
    
    ifstream infile;
    infile.open("names.txt");
    string lineInfo ;
    
    LOG("Reading file..." << std::endl)
    
    //While the file hasn't fully been read
    while(!infile.eof()){
        
        LOG("Line started..." << std::endl);
        
        //Store line in LineInfo
        getline(infile,lineInfo);
        LOG("Line reads: " << lineInfo << std::endl)
        //Check if in prefix section
        if( lineInfo == "-Prefix")
            preCheck = true;
        //If in section but not the sectopn Title
        if(preCheck == true && lineInfo!="-Prefix"){
            preNum ++;
            prefixLines.push_back(lineInfo);
        }
        
        if( lineInfo == "-Func")
            funcCheck = true;
        
        
        //If in section but not the sectopn Title
        if(preCheck == true && lineInfo!="-Func"){
            funNum ++;
            funcLines.push_back(lineInfo);
        }
        
        
        if( lineInfo == "-Var")
            varCheck = true;
        //If in section but not the sectopn Title
        if(preCheck == true && lineInfo!="-Var"){
            
            varNum ++;
            varLines.push_back(lineInfo);
        }
        
        if( lineInfo == "-Const")
            constCheck = true;
        //If in section but not the sectopn Title
        if(constCheck == true && lineInfo!="-Const"){
            
            constNum ++;
            constLines.push_back(lineInfo);
        }
        
        LOG("Line read" << std::endl)
        cout<< constLines[constNum] <<endl;
    }
    infile.close();
    preCheck = false;
    varCheck =false;
    funcCheck =false;
}

string genName::getFunc(){
    
    string nameTemp;
    nameTemp = prefixLines[randRange(0, preNum)] + funcLines[randRange(0, funNum)];
    
    usedNames.push_back(nameTemp);
    
    for(int i = 0; i<5;i++){
        int d = 0;
        bool check = false;
        while(d<numNames){
            
            if(nameTemp == usedNames[d]){
            
            nameTemp = prefixLines[randRange(0, preNum)] + funcLines[randRange(0, funNum)];
                check = true;
            }
            
            d++;
        }
        if(check == false) break;
        
    }
    
    numNames ++;
    
    
    return nameTemp;
}


string genName::getVar(){
    
    string nameTemp;
    nameTemp = prefixLines[randRange(0, preNum)] + varLines[randRange(0, preNum)];

    usedNames.push_back(nameTemp);
    
    for(int i = 0; i<5;i++){
        int d = 0;
        bool check = false;
        while(d<numNames){
            
            if(nameTemp == usedNames[d]){
                
                nameTemp = prefixLines[randRange(0, preNum)] + varLines[randRange(0, varNum)];
                check = true;
            }
            
            d++;
        }
        if(check == false) break;
        
    }
    
    numNames ++;
    

    
    return nameTemp;
}




string genName::getConst(){
    
    string nameTemp;
    nameTemp =  constLines[randRange(0, constNum)];
    
    usedNames.push_back(nameTemp);
    
    for(int i = 0; i<5;i++){
        int d = 0;
        bool check = false;
        while(d<numNames){
            
            if(nameTemp == usedNames[d]){
                
                nameTemp = constLines[randRange(0, constNum)];
                check = true;
            }
            
            d++;
        }
        if(check == false) break;
        
    }
    
    numNames ++;
    
    
    
    return nameTemp;
}

genName::~genName() {};
















