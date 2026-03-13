#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cctype>
#include <stdlib.h>
using namespace std;

string arr[100001];
map<string, int> mp;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        arr[i] = str;
        mp[str] = i;
    }

    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;

        if(isdigit(str[0])) cout << arr[stoi(str)] << "\n";
        else cout << mp[str] << "\n";
    }

    return 0;
}