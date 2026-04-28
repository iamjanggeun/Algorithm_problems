#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> numList;
vector<int> answers;

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void recursive(string combination, string candidate) {
    if(combination != "") numList.insert(stoi(combination));

    for(int i = 0; i < candidate.size(); i++) {
        recursive(combination + candidate[i], candidate.substr(0, i) + candidate.substr(i + 1));
    }
}

int solution(string numbers) {
    recursive("", numbers);
    int answer = 0;
    for(auto e : numList) if(isPrime(e)) answers.push_back(e);
    answer = answers.size();
    return answer;
}