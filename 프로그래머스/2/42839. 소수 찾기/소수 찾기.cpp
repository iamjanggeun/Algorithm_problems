#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <stdlib.h>
using namespace std;

bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    unordered_set<int> candidate_nums;

    sort(numbers.begin(), numbers.end());

    do {
        for(int len = 1; len <= numbers.length(); len++) {
            int num = stoi(numbers.substr(0, len));
            candidate_nums.insert(num);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));

    for(auto& e : candidate_nums) {
        if(isPrime(e)) answer++;
    }

    return answer;
}

