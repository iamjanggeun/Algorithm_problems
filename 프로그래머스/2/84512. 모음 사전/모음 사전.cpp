#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt = 0;
string candidate = "AEIOU";
int answer = 0;
string target = "";

void dfs(string word) {
    if(word == target) {
        answer = cnt;
        return;
    }
    
    if(word.length() == 5) return;

    for(int i = 0; i < 5; i++) {
        cnt++;
        dfs(word + candidate[i]);    
    }
}

int solution(string input) {
    target = input;
    dfs("");
    return answer;
}