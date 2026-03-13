#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

int freq[26];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') str[i] = (str[i] - 'a' + 13) % 26 + 'a';
        else if(str[i] >= 'A' && str[i] <= 'Z') str[i] = (str[i] - 'A' + 13) % 26 + 'A';
    }

    cout << str;
    return 0;
}