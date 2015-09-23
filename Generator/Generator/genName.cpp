#include "genName.h"
#include "logger.h"
#include "classDef.h"
#include <iterator>

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
    
    bool symbols = true;
    
    LOG("Reading file..." << std::endl)
    
    //While the file hasn't fully been read and no errors have happened in reading it.
    while(infile) {
        
        //Store line in LineInfo
        getline(infile, lineInfo);
        
        
        
        if (symbols){
            lines["Symbols"].push_back(lineInfo);
            
            if(lineInfo== "$SYMBOLS$"){
                symbols = false;
            }
            
        }else{
        if (lineInfo[0] == '-') {
            varKey = lineInfo.substr(1, lineInfo.size() );
        } else if(lineInfo[0] == '#'){
            //Nuthin
        }else{
            lines[varKey].push_back(lineInfo);
        }
        
        LOG("Line reads: " << lineInfo)
        }
    }
    
    infile.close();
    
    
}
inline bool isSpecial(const char c)
{
    
    return c == '!' || c == '@' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '~'
    || c == '+'|| c == '?' ;
}



string genName::get(const string& type, const vector<classDef::variable>& v){
    
    string name = "base_name";
    LOG("Getting name of type " << type)

    /*
     
     Special symbols:
        '!' = .post
        '@' = type (the string passed in).
        '#' = Comment line. Ignored when read in.
        '$' =
        '%' = .pre
        '^' =
        '&' =
        '*' =
        '~' =
        '+' =
        '?' = 
     */
    
    const vector<string>& ref = lines[type];
    
    if(ref.size() == 0){
        for(int i ;i <4 ; ++i){
            
        char c = randRange('a', 'z');
        name +=c;
        }
            
        
        
        
    } else {
        name = ref[randRange(0, ref.size()-1)];
        
        for (string::iterator i = name.begin() ; i < name.end();i++ ){
            int b;
            
        insert_iterator<string> a(name, i);
            
            char c = name[b];
            char h = '\0';
            
            if(isSpecial(c)==true){
                h =c;
                string add = genName::get(type + "." + h);
                a = add[b];
                
            }
            b++;
        }
        
    }
    
    
    return name;
}

















