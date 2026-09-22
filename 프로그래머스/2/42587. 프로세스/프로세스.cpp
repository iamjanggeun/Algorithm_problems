#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    
    int answer = 0;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }
    
    while(!q.empty()) {
        
        auto cur = q.front();
        q.pop();
        
        bool priority = false;
        
        for(int i = 0; i < q.size(); i++) {
            auto temp = q.front();
            q.pop();
            
            if(temp.first > cur.first) priority = true;
            q.push(temp);
        }
        
        if(priority) q.push(cur);
        else {
            answer++;
            
            if(cur.second == location) return answer;
        }
    }
    return answer;
}