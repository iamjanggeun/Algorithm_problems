#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long end = 1LL * (*max_element(times.begin(), times.end())) * n;
    long long start = 0;
    
    while(start <= end) {
        long long mid = start + (end - start) / 2;
        long long people = 0;
        
        for(const auto& t : times) {
            people += mid / t;
            
            if(people >= n) break;
        }
        
        if(people >= n) {
            answer = mid;
            end = mid - 1;
        }
        else start = mid + 1;
    }
        
    return answer;
}