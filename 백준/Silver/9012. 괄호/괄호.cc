/*********************************************************************
* Author:            Janggeun
* Date:              2026-03-08
* Project Name:      Algorithm Study
* Problem Name:      BOJ 9012번 - 괄호
* Description:       스택 / 문자열
*********************************************************************/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string str;
        stack<char> s;
        cin >> str;

        for(int i = 0; i < str.size(); i++) {
            if(!s.empty() && s.top() == '(' && str[i] == ')') {
                s.pop();
            }
            else s.push(str[i]);
        }

        if(s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}