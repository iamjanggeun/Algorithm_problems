#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    sort(dungeons.begin(), dungeons.end());
    do {
        int cnt = 0;
        int temp = k;

        for(int i = 0; i < dungeons.size(); i++) {
            if(temp >= dungeons[i][0]) {
                cnt++;
                temp -= dungeons[i][1];
            }
            else break;
        }
        answer = max(answer, cnt);
        if(answer == dungeons.size()) return answer;
    } while(next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}