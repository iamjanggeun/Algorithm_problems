#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int temp[3];

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5}; 
    vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == a[i % a.size()]) temp[0]++;
        if(answers[i] == b[i % b.size()]) temp[1]++;
        if(answers[i] == c[i % c.size()]) temp[2]++;
    }

    int max_score = max({temp[0], temp[1], temp[2]});
    int idx = 0;
    for(auto e : temp) {
        if(e == max_score) answer.push_back(idx + 1);
        idx++;
    }

    return answer;
}