#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    vector<int> v;
    vector<int> v2;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        v.push_back(s[i] - 'a');
        v2.push_back(s[i] - 'a');
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        if(v[i] != v2[i]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    return 0;
}