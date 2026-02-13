//백준_3986_좋은 단어
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<char> s;
    int cnt = 0;

    cin >> n;

    while(n--) {
        string word;

        cin >> word;

        for(int i = 0; i < word.size(); i++) {
            if(s.empty() || s.top() != word[i]) {
                s.push(word[i]);
            }
            else if(s.top() == word[i]) {
                s.pop();
            }
            else continue;
        }
        if(s.empty()) cnt++;

        while(!s.empty()) s.pop();
    }

    cout << cnt;
    return 0;
}