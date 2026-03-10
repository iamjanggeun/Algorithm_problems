/*********************************************************************
* Author:            Janggeun
* Date:              2026-03-10
* Project Name:      Algorithm Study
* Problem Name:      BOJ 17298 - 오큰수
* Description:       단조 스택 (Monotonic Stack)
*********************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n, num;
vector<int> v;
stack<int> s;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    vector<int> ans(n, -1);
    stack<int> s;

    for(int i = 0; i < n; i++) {
        while(!s.empty() && v[s.top()] < v[i]) {
            ans[s.top()] = v[i]; 
            s.pop();             
        }
        s.push(i); 
    }
    for(auto e : ans) cout << e << " ";
    return 0;
}