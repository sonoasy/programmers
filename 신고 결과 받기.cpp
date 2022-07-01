#include <string>
#include <vector>
#include<sstream> 
#include<map>
#include<set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.assign(id_list.size(),0);
    //map,string,string-int 에서 신고 횟수 체크 
    //k이상 신고 됬으면 +1 
    map<string,set<string>>m;
    
    map<string,int>a;
    for(int i=0;i<id_list.size();i++){
        
        a[id_list[i]]=i;
    }
    
    //신고된 report
    for(auto rep:report){
        
        stringstream ss(rep);
        string from,to;
        ss>>from>>to;
        
        m[to].insert(from);
        
        
    }
    for(auto singo:m){
        
        if(singo.second.size()>=k){
           for(auto bye: singo.second){
               answer[a[bye]]++;
           }
               
        }
        
        
    }
    
    
    
    
    return answer;
}
