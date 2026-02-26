//문자열 처리 연습 중
//백준_1972_놀라운 문자열
#include <iostream>
#include <string>
#include <stdlib.h>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        string str;
        cin >> str;
        if(str == "*") break;

        int len = str.size();
        bool isSurprise = true;

        for(int i = 0; i < len - 2; i++) {
            set<string> s;
            for(int j = 0; j + i + 1 < len; j++) {
                string pair = "";
                pair += str[j];
                pair += str[j + i + 1];

                if(s.find(pair) != s.end()) {
                    isSurprise = false;
                    break;
                }
                s.insert(pair);  
            }
            if(!isSurprise) break;
        }

        if(isSurprise) cout << str << " is " << "surprising.\n";
        else cout << str << " is " << "NOT surprising.\n";
    }
    return 0;
}