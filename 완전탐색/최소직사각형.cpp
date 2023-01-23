#include <string>
#include <vector>
#include<iostream> 
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    //w,h 최대값 각자 구하고 더 작아도 만족하는지 확인
    int w_max=0;
    int h_max=0;
    for(int i=0;i<sizes.size();i++){
        w_max=max(w_max,min(sizes[i][0],sizes[i][1]));
        h_max=max(h_max,max(sizes[i][0],sizes[i][1]));
    }

    answer=w_max*h_max;

    return answer;
}
