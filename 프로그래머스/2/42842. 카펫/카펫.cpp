#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int space = brown + yellow;

    for(int height = 3; height <= sqrt(space); height++) {
        if(space % height == 0) {
            int row = space / height;
            if((row + height) * 2 - 4 == brown) {
                answer.push_back(row);
                answer.push_back(height);
            }
        }
    }
    return answer;
}

int main() {
    int a = 24;
    int b = 24;

    for(auto e : solution(a, b)) {
        cout << e << " ";
    }
}