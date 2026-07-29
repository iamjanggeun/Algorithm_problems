#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;
    
    vector<unordered_set<int>> dp(9);
    int init = 0;
    for(int i = 1; i < 9; i++) {
        init = init * 10 + N;
        dp[i].insert(init);
    }
    
    for(int i = 2; i <= 8; i++) {
        for(int j = 1; j < i; j++) {
            for(auto op1 : dp[j]) {
                for(auto op2 : dp[i - j]) {
                    dp[i].insert(op1 + op2);
                    dp[i].insert(op1 - op2);
                    dp[i].insert(op1 * op2);
                    if(op2 != 0) dp[i].insert(op1 / op2);
                }
            }
        }
        if(dp[i].count(number)) return i;
    }
    
    return -1;
}