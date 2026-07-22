#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <unordered_set>
using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    unordered_set<int> numList;
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    
    do {
        for(int len = 1; len <= numbers.size(); len++) {
            int num = stoi(numbers.substr(0, len));
            numList.insert(num);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    for(auto& e : numList) {
        if(isPrime(e)) answer++;
    }
    
    return answer;
}