#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
    1. queue에 대기 중 높은 우선순위 존재 시 q.push()
    2. 없으면 실행 후 종료. Q.pop()
*/

// int solution(vector<int> priorities, int location) {
//     int answer = 0;
    
//     // location 마킹
//     queue<pair<int, int>> Q;
//     for(int i = 0; i < priorities.size(); i++) {
//         if(i == location) Q.push({priorities[i], 1});
//         Q.push({priorities[i], 0});
//     }
    
//     // queue 순회
//     while(!Q.empty()) {
//         pair<int, int> cur = Q.front();
//         Q.pop();
//         bool priority = false;
        
//         for(int i = 0; i < Q.size(); i++) {
//             pair<int, int> temp = Q.front();
//             Q.pop();
            
//             if(temp.first > cur.first) priority = true;
            
//             Q.push(temp);
//         }
        
//         if(priority) Q.push(cur);
//         else {
//             answer++;
            
//             if(cur.second == 1) return answer;
//         }
//     }
    
//     return answer;
// }

// 우선순위 큐 STL 사용 방식

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> Q;
    priority_queue<int> PQ;
    int ans = 0;
    
    for(int i = 0; i < priorities.size(); i++) {
        Q.push({priorities[i], i});
        PQ.push({priorities[i]});
    }
    
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        if(cur.first == PQ.top()) {
            ans++;
            PQ.pop();
            
            if(cur.second == location) return ans;
        }
        else Q.push(cur);
    }
    return ans;
}
