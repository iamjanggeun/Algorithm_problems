#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool visited[100001];
vector<string> ans;

bool dfs(vector<vector<string>> tickets, string start, int idx) {

    ans.push_back(start);
    
    if (idx == tickets.size()) return true;
    
    for(int i = 0; i < tickets.size(); i++) {
        if(visited[i]) continue;
        
        if(tickets[i][0] == start) {
            visited[i] = true;
            if(dfs(tickets, tickets[i][1], idx + 1)) return true;
            visited[i] = false;
            ans.pop_back();            
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN", 0);
    
    return ans;
}