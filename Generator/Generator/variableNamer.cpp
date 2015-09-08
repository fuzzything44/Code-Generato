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
            lines[0].second.push_back(lineInfo);
            prefixLines.push_back(lineInfo);
        }
        
        if( lineInfo == "-Func")
            funcCheck = true;
        
        
        //If in section but not the sectopn Title
        if(preCheck == true && lineInfo!="-Func"){
            lines[1].second.push_back(lineInfo);
            funcLines.push_back(lineInfo);
        }
        
        
        if( lineInfo == "-Var")
            varCheck = true;
        //If in section but not the sectopn Title
        if(preCheck == true && lineInfo!="-Var"){
            
           lines[2].second.push_back(lineInfo);
            varLines.push_back(lineInfo);
        }
        
        if( lineInfo == "-Const")
            constCheck = true;
        //If in section but not the sectopn Title
        if(constCheck == true && lineInfo!="-Const"){
            
            lines[3].second.push_back(lineInfo);
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
     lines[1].first ="Func";
     
    //Var to store randome name
    string nameTemp;
     //Store random name in nametemp
     nameTemp = lines[0].second[randRange(0, lines[0].second.size())] +lines[1].second[randRange(0, lines[1].second.size())] ;
    usedNames.push_back(nameTemp);
     
     
    //return nameTemp
    return nameTemp;
}


 string genName::getVar(){
     lines[2].first ="Var";
    string nameTemp;
     nameTemp = lines[0].second[randRange(0, lines[0].second.size())] +lines[2].second[randRange(0, lines[2].second.size())] ;
    usedNames.push_back(nameTemp);
     
     
    return nameTemp;
}




string genName::getConst(){
     lines[3].first ="Const";
    string nameTemp;
    nameTemp = lines[0].second[randRange(0, lines[0].second.size())] +lines[3].second[randRange(0, lines[3].second.size())] ;

    usedNames.push_back(nameTemp);
    
    return nameTemp;
}

string genName::get(string type){
    
    string name;
    if(type == "Func" )
     name=    genName::getFunc();
    
    if(type == "Var" )
       name = genName::getVar();
    
    if(type == "Const" )
       name = genName::getConst();
    
   return name;
}

















