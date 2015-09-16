#include "genName.h"
#include "logger.h"
#include "classDef.h"

using std::string;
using std::ifstream;

std::map<string, std::vector<string> > genName::lines;

void genName::init() {
   
    ifstream infile;
    infile.open("names.txt");
    string lineInfo ;
    
    // For what vector to add the info to.
    string varKey;
    
    
    LOG("Reading file..." << std::endl)
    
    //While the file hasn't fully been read and no errors have happened in reading it.
    while(infile) {
        
        //Store line in LineInfo
        getline(infile, lineInfo);
        
        if (lineInfo[0] == '-') {
            varKey = lineInfo;
            lines[varKey];
            
        }
        
        lines[varKey].push_back(lineInfo);
        
        LOG("Line reads: " << std::endl)
    }
    
    infile.close();
    
    
}


string genName::get(string type){
    
    
    string name;
    const std::vector<string>& ref = lines[type];
    if (type != "Const"){
        name = lines["-Prefix"][randRange(0, lines[type].size())] +ref[randRange(0, lines[type].size())];
    }
    name = ref[randRange(0, lines[type].size())];
    
    
    
    return name;
}

















