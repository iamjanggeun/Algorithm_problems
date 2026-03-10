/*********************************************************************
* Author:            Janggeun
* Date:              2026-03-10
* Project Name:      Algorithm Study
* Problem Name:      BOJ 1436번 - 영화감독 숌
* Description:       브루트포스
*********************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int i = 666;

    while(n != 0) {
        if(to_string(i).find("666") != string::npos) n--;
        i++;
    }

    cout << i - 1;

    return 0;
}