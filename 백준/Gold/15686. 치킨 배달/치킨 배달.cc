/*********************************************************************
* Author:            Janggeun
* Date:              2026-04-05
* Project Name:      Algorithm Study
* Problem Name:      BOJ 15686번 - 치킨 배달
* Description:       완전 탐색 / 조합 or 순열
*********************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a[54][54];
vector<vector<int>> selector;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

void combination(int start, vector<int> v) {
    if(v.size() == m) {
        selector.push_back(v);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++) {
        v.push_back(i);
        combination(i, v);
        v.pop_back();
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) home.push_back({i, j});
            if(a[i][j] == 2) chicken.push_back({i, j});
        }
    }

    vector<int> v;
    combination(-1, v);
    
    int answer = 987654321;
    for(vector<int> s : selector) {
        int ret = 0;
        for(pair<int, int> h : home) {
            int minVal = 987654321;
            for(int num : s) {
                int dist = abs(h.first - chicken[num].first) 
                    + abs(h.second - chicken[num].second);
                minVal = min(minVal, dist);
            }
            ret += minVal;
        }
        answer = min(answer, ret);
    }
    cout << answer;
    return 0;
}