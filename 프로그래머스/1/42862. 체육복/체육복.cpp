#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int freq[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    fill(freq, freq + 32, 1);
    for(auto e : reserve) freq[e - 1] = 2;
    for(auto e : lost) {
        if(freq[e - 1] == 2) freq[e - 1]--;
        else freq[e - 1] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        if(freq[i] == 0) {
            if(freq[i - 1] == 2) {
                freq[i]++;
                freq[i-1]--;
            }
            else if((i + 1 < n) && freq[i + 1] == 2) {
                freq[i]++;
                freq[i + 1]--;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(freq[i] > 0) answer++;
    }
    
    return answer;
}