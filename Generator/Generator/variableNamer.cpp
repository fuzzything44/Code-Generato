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
  
    
    
    lines["Prefix"] = vector<string>();
    
    
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
           lines["Prefix"].push_back(lineInfo);
            prefixLines.push_back(lineInfo);
        }
        
        if( lineInfo == "-Func")
            funcCheck = true;
        
        
        //If in section but not the sectopn Title
        if(preCheck == true && lineInfo!="-Func"){
            lines["Func"].push_back(lineInfo);
            funcLines.push_back(lineInfo);
        }
        
        
        if( lineInfo == "-Var")
            varCheck = true;
        //If in section but not the sectopn Title
        if(preCheck == true && lineInfo!="-Var"){
            
          lines["Func"].push_back(lineInfo);
            varLines.push_back(lineInfo);
        }
        
        if( lineInfo == "-Const")
            constCheck = true;
        //If in section but not the sectopn Title
        if(constCheck == true && lineInfo!="-Const"){
            
            lines["Const"].push_back(lineInfo);
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

///




string genName::get(string type){
    
    
    string name;
    
    
    if (type != "Const"){
    name = lines[type][randRange(0, lines[type].size())] +lines[type][randRange(0, lines[type].size())];
    }
    name = lines[type][randRange(0, lines[type].size())];
    
   return name;
}

















