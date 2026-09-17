#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> PQ;
    
    for(auto e : scoville) PQ.push(e);
    
    while(PQ.size() >= 2 && PQ.top() < K) {
        int temp = PQ.top();
        PQ.pop();
        
        temp += PQ.top() * 2;
        PQ.pop();
        
        PQ.push(temp);
        answer++;
    }
    
    if(PQ.top() < K) return -1;
    
    return answer;
}