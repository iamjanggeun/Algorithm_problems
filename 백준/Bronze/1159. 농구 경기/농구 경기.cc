#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N;
int freq[26];
int main()
{
    cin >> N;
    string s;
    int idx = 0;
    bool isValid = false;
    for(int i = 0; i < N; i++) {
        cin >> s;
        freq[s[0] - 'a']++;
    }

    for(auto e : freq) {
        if (e >= 5) {
            char c = idx + 'a';
            cout << c;
            isValid = true;
        }
        idx++;
    }

    if(!isValid) cout << "PREDAJA";
    return 0;
}