#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 논문 3(n)편 중 5(h)번 이상 인용된 논문이 5(h)편 이상이고, 나머지 논문이 5(h)번 이하 인용 시 h의 최댓값

/*
    [3, 0, 6, 1, 5] -> [6, 5, 3, 1, 0]
*/
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());
    
    for(int i = 0; i < citations.size(); i++) {
        if(citations[i] >= i + 1) {
            answer = max(answer, i + 1);
        }
    }
    
    return answer;
}