#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());

    int right = people.size() - 1;
    int left = 0;

    while(left <= right) {
        if(right == left) {
            answer++;
            break;
        }

        if(people[right] + people[left] <= limit) {
            right--;
            left++;
        }

        else right--;
        answer++;
    }

    return answer;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> p = {70, 50, 80, 50};
    int lim = 100;

    cout << solution(p, lim);

    return 0;
}