/*********************************************************************
* Author:            Janggeun
* Date:              2026-03-06
* Project Name:      Algorithm Study
* Problem Name:      BOJ 2870번 - 수학숙제
* Description:       문자열 처리
*********************************************************************/

// 100글자 이상이라 수 처리가 매우 힘들어 vector<string>으로 문자열로 처리

#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;

bool compare(string a, string b) {
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<string> v;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        string temp = "";

        for(int j = 0; j < str.size(); j++) {
            if(isdigit(str[j])) {
                temp += str[j];
            }
            else {
                if(!temp.empty()) {
                    while(temp.size() > 1 && temp[0] == '0') temp.erase(0, 1);
                    v.push_back(temp);
                    temp = "";
                }
            }
        }

        // 문자열이 숫자로 마무리된 경우 (ex. zed99면 temp에 99가 들어가 있는 상황이므로 한번 더 해주기)
        if(!temp.empty()) {
            while(temp.size() > 1 && temp[0] == '0') temp.erase(0, 1);
            v.push_back(temp);
        }
    }

    sort(v.begin(), v.end(), compare);
    for(auto e : v) cout << e << "\n";

    return 0;
}