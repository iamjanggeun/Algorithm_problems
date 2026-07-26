#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int ans = 0;
    unordered_set <int> numList;
    sort(numbers.begin(), numbers.end());
    
    do {
        for(int len = 1; len <= numbers.size(); len++) {
            int num = stoi(numbers.substr(0, len));
            numList.insert(num);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    for(auto& e : numList) {
        if(isPrime(e)) ans++;
    }
    
    return ans;
}