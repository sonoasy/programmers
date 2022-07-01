#include <string>
#include <vector>
#include<map>
#include<sstream>


using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> m;
    vector<string>states;
    
    for(int i=0;i<record.size();i++){
        int idx=0;
        string str[3];
        string token;
        stringstream ss(record[i]);
        while(ss>>token){
            str[idx++]=token;
            
        }
       
        
        if(str[0]=="Enter"){
            states.push_back("님이 들어왔습니다.");
            answer.push_back(str[1]); //넘버 저장 
            m[str[1]]=str[2]; //넘버-이름
        }
        else if(str[0]=="Leave"){
            states.push_back("님이 나갔습니다.");
            answer.push_back(str[1]); //넘버 저장 
        }
        else{ //change일 경우 
            m[str[1]]=str[2];
        }
        
    }
    
    for(int i=0;i<answer.size();i++){
        answer[i]=m[answer[i]]+states[i];
    }
    
    return answer;
}
