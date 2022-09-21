#include <string>
#include <vector>
#include<iostream>
#include <sstream>
#include<map>
#include<cmath>
#include<set>
using namespace std;

int defaultTime;
int defaultFee;
int extraTime;
int extraFee; 
int getTime(string a, string b){
    //시간차를 구함  a가 뒷시간
    string a_hour,b_hour; 
    string a_minutes,b_minutes;
    for(int i=0;i<2;i++){
       a_hour+=a[i];
       b_hour+=b[i];
   }
   for(int i=3;i<=4;i++){
       a_minutes+=a[i];
       b_minutes+=b[i];
   }     
   
    int hourgap;
    int minutegap;
    int i_a_hour=stoi(a_hour);
    int i_b_hour=stoi(b_hour);
    int i_a_minutes=stoi(a_minutes);
    int i_b_minutes=stoi(b_minutes);
    if(i_a_minutes<i_b_minutes){
        i_a_hour-=1;
        i_a_minutes+=60;
           
    }
    minutegap=i_a_minutes-i_b_minutes;     
    hourgap=i_a_hour-i_b_hour;
    hourgap*=60;
    
    return (minutegap+hourgap);
}

int getFinalFee(int finalTime){
    int finalFee=0; 
    if(finalTime<=defaultTime)finalFee=defaultFee;
        else{
            finalFee+=defaultFee;
            finalTime-=defaultTime; 
            finalFee+=(ceil((float)finalTime/extraTime))*extraFee;  
           
        }   
    return finalFee;
    
}
//요금 계산하기 
         //누적 시간이 기본시간 이내이면 기본요금을 내고 
        //초과부터는 기본요금 + (누적시간 - 기본시간)/단위시간* 단위요금 계산 
                             //나누어 안되면 올림하기 
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    defaultTime=fees[0];
    defaultFee=fees[1];
    extraTime=fees[2];
    extraFee=fees[3]; 
    
    vector<string>arr;
    arr.assign(10001,"");
    set<int>s;
    map<int,int>res;
    for(int i=0;i<records.size();i++){
        
        stringstream ss(records[i]);
        string times, num, state;
        float finalTime; 
        float finalFee;
        ss >> times >> num >> state;
        
        if(state=="IN"){
            
            arr[stoi(num)]=times;
            //차의 목록
            s.insert(stoi(num));
           
        }
        else if(state=="OUT"){
            
             res[stoi(num)]+=getTime(times,arr[stoi(num)]);
             arr[stoi(num)]="";  
            cout<<num<<" "<<res[stoi(num)]<<'\n';
        }      
    }   

    //다끝났는데 out되지 않은게 있다면 
    for(int i=0;i<10001;i++){
        if(arr[i]!=""){
            res[i]+=getTime("23:59",arr[i]);
            
        }
    }
    
    for(int i=0;i<10001;i++){
        if(res[i]>0){
            answer.push_back(getFinalFee(res[i]));
        }
    }
    

    return answer;
}
