#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int bfs(int n, int start, int u, int v, vector<vector<int>> adj) {
    queue<int> Q;
    vector<bool> visited(n + 1, 0);
    int count = 1;

    Q.push(start);
    visited[start] = true;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for(auto& next : adj[cur]) {
            if(visited[next]) continue;
            if((cur == u && next == v) || (cur == v && next == u)) continue;
            count++;
            Q.push(next);
            visited[next] = true;
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 2147483647;
    //1. 연결노드 저장
    vector<vector<int>> adj(n + 1);
    for(auto& w : wires) {
        adj[w[0]].push_back(w[1]);
        adj[w[1]].push_back(w[0]);
    }
    
    for(auto& w : wires) {
        int u = w[0];
        int v = w[1];

        int cnt = bfs(n, u, u, v, adj);
        int cnt2 = n - cnt;

        answer = min(answer, abs(cnt - cnt2));
    }

    return answer;
}