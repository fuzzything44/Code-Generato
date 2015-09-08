#include "variableNamer.h"
#include "logger.h"
#include "classDef.h"

using namespace std;

void genName::init() {

    int numDef = 0;
    //Check Vars
    bool preCheck = false;
    bool funcCheck = false;
    bool varCheck = false;
    bool constCheck = false;
    //Number of names
   
   
    //Store Lines Info
    prefixLines.push_back("");
    funcLines.push_back("");
    varLines.push_back("");
    constLines.push_back("");
    usedNames.push_back("");
    
    lines[0].second.push_back("");
    
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
           
            prefixLines.push_back(lineInfo);
        }
        
        if( lineInfo == "-Func")
            funcCheck = true;
        
        
        //If in section but not the sectopn Title
        if(preCheck == true && lineInfo!="-Func"){
            
            funcLines.push_back(lineInfo);
        }
        
        
        if( lineInfo == "-Var")
            varCheck = true;
        //If in section but not the sectopn Title
        if(preCheck == true && lineInfo!="-Var"){
            
           
            varLines.push_back(lineInfo);
        }
        
        if( lineInfo == "-Const")
            constCheck = true;
        //If in section but not the sectopn Title
        if(constCheck == true && lineInfo!="-Const"){
            
            
            constLines.push_back(lineInfo);
        }
        
        LOG("Line read" << std::endl)
        cout<< constLines[constLines.size()] <<endl;
    }
    infile.close();
    
    preCheck = false;
    funcCheck = false;
    varCheck = false;
    constCheck = false;
}

 string genName::getFunc(){
    //Var to store randome name
    string nameTemp;
     //Store random name in nametemp
    nameTemp = prefixLines[randRange(0, prefixLines.size())] + funcLines[randRange(0, funcLines.size())];
    usedNames.push_back(nameTemp);
     
     
    //return nameTemp
    return nameTemp;
}


 string genName::getVar(){
    
    string nameTemp;
    nameTemp = prefixLines[randRange(0, prefixLines.size())] + varLines[randRange(0, prefixLines.size())];
    usedNames.push_back(nameTemp);
     
     
    return nameTemp;
}




string genName::getConst(){
    
    string nameTemp;
    nameTemp = constLines[randRange(0, prefixLines.size())];
    usedNames.push_back(nameTemp);
    
    return nameTemp;
}

string genName::get(string type){
    
    
    
    
   return "";
}

















