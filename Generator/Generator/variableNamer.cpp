#include "variableNamer.h"
#include "logger.h"
#include "classDef.h"

using namespace std;

void genName::init() {

    
    //Check Vars
   
    //Number of names
   
   
    //Store Lines Info
  
    
    
    lines["Prefix"] = vector<string>();
    
    
    ifstream infile;
    infile.open("names.txt");
    string lineInfo ;
    string varKey;
    
    
    LOG("Reading file..." << std::endl)
    
    //While the file hasn't fully been read
    while(!infile.eof()){
        
        LOG("Line started..." << std::endl);
        
        //Store line in LineInfo
        getline(infile,lineInfo);
        
        if (lineInfo[0] == '-'){
            varKey = lineInfo;
            lines[varKey];
            
        }
        
        lines[varKey].push_back(lineInfo);
        
        
        
        
        LOG("Line read" << std::endl)
            }
    infile.close();
    
    
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

















