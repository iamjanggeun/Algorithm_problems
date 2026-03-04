/*********************************************************************
* Author:            Janggeun
* Date:              2026-03-04
* Project Name:      Algorithm Study
* Problem Name:      BOJ 4659번 - 비밀번호 발음하기
* Description:       그냥 구현 문제
*********************************************************************/

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (cin >> s && s != "end") {
        bool isInvalid = false; // 잘못된 경우 true
        bool hasVowel = false;
        int vCnt = 0, cCnt = 0;
        char prev = -1;

        for (char curr : s) {
            if (isVowel(curr)) {
                vCnt++;
                cCnt = 0;
                hasVowel = true;
            } 
            else {
                cCnt++;
                vCnt = 0;
            }

            // 조건 2: 3개 연속 여부
            if (vCnt >= 3 || cCnt >= 3) isInvalid = true;

            // 조건 3: 2개 연속 여부 (ee, oo 제외)
            if (prev == curr && curr != 'e' && curr != 'o') isInvalid = true;

            prev = curr;
        }

        // 조건 1: 모음 포함 여부
        if (!hasVowel) isInvalid = true;

        if (isInvalid) cout << "<" << s << "> is not acceptable.\n";
        else cout << "<" << s << "> is acceptable.\n";
    }

    return 0;
}