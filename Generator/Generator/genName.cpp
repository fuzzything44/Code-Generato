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
        
        
        
        if (symbols) {
            lines["Symbols"].push_back(lineInfo);
            
            if(lineInfo == "$SYMBOLS$") {
                symbols = false;
            }
        } else {
            if (lineInfo[0] == '-') {
                varKey = lineInfo.substr(1, lineInfo.size() );
            } else if(lineInfo[0] == '#') {
                //Nuthin
            } else {
                lines[varKey].push_back(lineInfo);
            }
        
            LOG("Line reads: " << lineInfo)
        } // End symbols if/else
    } // End while
    
    infile.close();
    
    
} // End function


// Determines if the vector has a 1-char length string equal to the given char.
inline bool containsChar(const char c, const vector<string>& symbols)
{
    // Go through all symbols.
    for (auto i = symbols.cbegin(); i != symbols.cend(); i++) {
        // If a symbol matches the character, return true.
        if (*i == to_string(c) ) {
            return true;
        }
    }
    
    // No match found. Return false.
    return false;
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
    
    if(ref.size() == 0) {
        for(int64 i = randRange(10, 20); i > 0 ; i--) {
            
        char c = randRange('a', 'z');
        name += c;
    }
            
        
        
        
    } else {
        name = ref[randRange(0, ref.size()-1)];
        
<<<<<<< Updated upstream
        for (auto i = name.begin() ; i < name.end();i++ ) {
            if(containsChar(*i, lines["Symbols"]) ) {
                insert_iterator<string> a(name, i);
                string add = genName::get(type + "." + *i);
                LOG(" Inserting string \"" << add << "\" to string\"" << name << "\"")
                for (auto j = add.cbegin(); j != add.cend(); j++) {
                    if ( j != add.cbegin() ) {
                        a = *j;
                    } else {
                        *i = *j;
                    } // End if/else for insert.s
                } // End insert for.
=======
        for (auto i = name.begin() ; i < name.end();i++ ){
            int b = 0;
            
        insert_iterator<string> a(name, i);
            
            char c = name[b];
            char h = '\0';
            
            if(isSpecial(c)==true){
                h =c;
                string add = genName::get(type + "." + h);
                a = add[b];
>>>>>>> Stashed changes
                
            } // End if it needs an insert
        } // End for
        
    } // End if/else.
    
    
    return name;
}

















