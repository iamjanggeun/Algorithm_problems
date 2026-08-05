#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    sort(dungeons.begin(), dungeons.end());

    do {
        int temp = k;
        int cnt = 0;
        for(auto e : dungeons) {
            if(temp < e[0]) break;
            temp -= e[1];
            cnt++;
        }
        answer = max(answer, cnt);
    } while(next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}