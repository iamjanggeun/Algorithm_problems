#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int left = 0;
    int sum = 0;
    
    int bestLeft = 0;
    int bestRight = sequence.size() - 1;
    int minLen = sequence.size() + 1;
    
    for(int right = 0; right < sequence.size(); right++) {
        sum += sequence[right];
        
        while(sum > k) {
            sum -= sequence[left];
            left++;
        }
        
        if(sum == k) {
            int len = right - left;
            
            if(len < minLen) {
                minLen = len;
                bestLeft = left;
                bestRight = right; 
            }
        }
    }
    
    
    return {bestLeft, bestRight};
}