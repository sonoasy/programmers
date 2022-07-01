#include <string>
#include <vector>
#include<map>
using namespace std;

int solution(string s) {
    map<string,int>m;
    m["zero"]=0;
    m["one"]=1;
    m["two"]=2;
    m["three"]=3;
    m["four"]=4;
    m["five"]=5;
    m["six"]=6;
    m["seven"]=7;
    m["eight"]=8;
    m["nine"]=9;
    string answer="";
    string tmp="";
    
    for(char c:s){
        if(isdigit(c))answer+=c;
        else{
            tmp+=c;
            
        }
        if(m.find(tmp)!=m.end()){
            answer+=to_string(m[tmp]);
            tmp="";
        }
        
    }
    
    
    return stoi(answer);
}
