#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//A = 65, a = 97, Z = 90, z = 122

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);

    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] = (s[i] - 'A' + 13)%26 + 'A';
        else if (s[i] >= 'a' && s[i] <= 'z') s[i] = (s[i] - 'a' + 13)%26 + 'a';
    }

    for(auto e : s) cout << e;
    return 0;
}