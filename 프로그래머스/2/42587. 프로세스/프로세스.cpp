#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    
    priority_queue<int> PQ;
    queue<pair<int, int>> Q;
    int answer = 0;
    
    for(int i = 0; i < priorities.size(); i++) {
        PQ.push(priorities[i]);
        Q.push({priorities[i], i});
    }
    
    while(!PQ.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        if(cur.first == PQ.top()) {
            answer++;
            PQ.pop();
            
            if(cur.second == location) return answer;
        }
        
        Q.push(cur);
    }
    
    return answer;
}