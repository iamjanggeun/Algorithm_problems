#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max1 = 0, max2 = 0;
    
    for(auto& e : sizes) {
        int big = max(e[0], e[1]);
        int small = min(e[0], e[1]);
        
        max1 = max(max1, big);
        max2 = max(max2, small);
    }
    
    answer = max1 * max2;
    return answer;
}