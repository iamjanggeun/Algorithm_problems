#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> Q;
    
    //큐에 priorities 넣기
    for(int i = 0; i < priorities.size(); i++) Q.push({priorities[i], i});
    
    //큐 순회
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        
        bool priority = false;
        
        for(int i = 0; i < Q.size(); i++) {
            pair<int, int> temp = Q.front();
            Q.pop();
            
            if(temp.first > cur.first) priority = true;
            
            Q.push(temp);
        }
        
        if(priority) Q.push(cur);
        else {
            answer++;
            
            if(cur.second == location) return answer;
        }
    }
        
    
    return answer;
}