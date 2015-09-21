#include "genName.h"
#include "logger.h"
#include "classDef.h"

using std::string;
using std::ifstream;

std::map<string, std::vector<string> > genName::lines;

using namespace std;

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
            varKey = lineInfo.substr(1, lineInfo.size() );
        } else {
            lines[varKey].push_back(lineInfo);
        }
        
        LOG("Line reads: " << lineInfo)
    }
    
    infile.close();
    
    
}


string genName::get(const string& type, const vector<classDef::variable>& v){
    
    string name = "base_name";
    LOG("Getting name of type " << type)


    
    const vector<string>& ref = lines[type];
    
    if (type != "Const"){
        name =
            lines["Prefix"]
            [randRange(0,
            lines["Prefix"].size())]
            + ref[randRange(0,
            lines[type].size())];
    }else {
    name = ref[randRange(0, lines[type].size())];
    }
    for(vector<classDef::variable>::const_iterator i =v.begin();i != v.end();++i){
        if(i->first == name){
            return genName::get(type,v);
            
        }
    }
    
    
    return name;
}

















