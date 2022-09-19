#include <string>
#include <vector>
#include<cmath>
#include<iostream> 
#include<algorithm>

using namespace std;

//10진수를 k진수로 바꾸기 

string TenTok(long long int a,int k){
    
    string tmp="";
    
    while(a>0){
        tmp+=to_string(a%k);
        a/=k;
    }
    reverse(tmp.begin(),tmp.end());
    return tmp; 
    
}

//k진수를 10진수로 바꾸기 
long long ktoTen(string a,int k){
    
    long long int tmp=0;
    for(int i=0;i<a.size();i++){
        tmp+=(a[i]-'0')*pow(k,a.size()-i-1);
        
    }    
    return tmp;
}


int isPrime(long long n){
    if(n<=1)return 0;
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1; 
}


int solution(int n, int k) {
  //소수 
    
    
    vector<bool>prime;
    int answer = 0;
 
    string a=TenTok(n,k);
    string p="";
   
    for(int i=0;i<a.size();i++){
        
        if(a[i]=='0'){
           
           if(p!=""){
             long long tmp=stoi(p);
             if(isPrime(tmp))answer++; 
             p="";   
           } 
            
        }
        else if(a[i]>'0' && a[i]<'9'){
            p+=a[i];
            if(i==a.size()-1 && p!=""){
            
                if(isPrime(stoul(p))){
                  answer++; 
                 }
             }
        }    
        
    }
  
 
    
    return answer;
}
