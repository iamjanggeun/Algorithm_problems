#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string s;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;
    int pos = s.find('*');

    string prefix = s.substr(0, pos);
    string suffix = s.substr(pos + 1);

    for(int i = 0; i < n; i++) {
        string s2;
        cin >> s2;

        if(s2.size() < prefix.size() + suffix.size()) cout << "NE" << "\n";
        else if(s2.substr(0, prefix.size()) == prefix && s2.substr(s2.size() - suffix.size()) == suffix) cout << "DA" << "\n";
        else cout << "NE" << "\n";
    }

    return 0;
}