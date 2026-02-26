//문자열 처리 연습중
//백준_16120_PPAP
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int len = str.size();
    string stack = "";

    for(int i = 0; i < len; i++) {
        stack.push_back(str[i]);

        if(stack.size() >= 4) {
            if(stack[stack.size() - 4] == 'P'
            && stack[stack.size() - 3] == 'P'
            && stack[stack.size() - 2] == 'A'
            && stack[stack.size() - 1] == 'P') {
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
            }
        }
    }

    if(stack == "P") cout << "PPAP";
    else cout << "NP";

    return 0;
}