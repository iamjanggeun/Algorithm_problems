#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;

void dfs(vector<int> numbers, int target, int sum, int idx) {
    // 배열 안의 정수 모두 사용하면 종료
    if(idx == numbers.size()) {
        if(sum == target) cnt++;
        return;
    }

    dfs(numbers, target, sum + numbers[idx], idx + 1);
    dfs(numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {

    dfs(numbers, target, 0, 0);

    return cnt;
}