#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt = 0;
string candidate = "AEIOU";
int answer = 0;
string target = "";

void dfs(string word) {
    cnt++;
    if(word == target) {
        answer = cnt;
        return;
    }
    
    if(word.length() >= 5) return;

    for(int i = 0; i < 5; i++) {
        dfs(word + candidate[i]);
    }
}

int solution(string tar) {
    target = tar;
    dfs("");
    return answer - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solution("AAAE");
    return 0;
}