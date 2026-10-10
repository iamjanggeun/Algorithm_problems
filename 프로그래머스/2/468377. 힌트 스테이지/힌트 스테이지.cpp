#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long dfs(int stage, vector<vector<int>>& cost, vector<vector<int>>& hint, vector<int>& haveHint) {
    
    int n = cost.size(); 
    
    int hintCount = min(haveHint[stage], n - 1);
    long long currentCost = cost[stage][hintCount];
    
    // 종단 조건
    if (stage == n - 1) return currentCost;
    
    // 힌트권 안 산 경우
    long long notBuy = currentCost + dfs(stage + 1, cost, hint, haveHint);
    
    // 힌트권 산 경우 힌트 추가
    for(int i = 1; i < hint[stage].size(); i++) {
        haveHint[hint[stage][i] - 1]++;
    }
    
    // 힌트권 산 경우
    long long buy = currentCost + hint[stage][0] + dfs(stage + 1, cost, hint, haveHint);
        
    // 백트래킹
    for(int i = 1; i < hint[stage].size(); i++) {
        haveHint[hint[stage][i] - 1]--;
    }
    
    return min(notBuy, buy);
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int answer = 0;
    
    vector<int> haveHint(cost.size(), 0);
    
    answer = dfs(0, cost, hint, haveHint);
    
    return answer;
}