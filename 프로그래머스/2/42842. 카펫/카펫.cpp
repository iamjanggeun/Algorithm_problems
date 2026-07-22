#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;

    for(int col = 3; col <= sqrt(area); col++) {
        if(area % col == 0) {
            int row = area / col;
            if(2*(row + col) - 4 == brown) {
                answer.push_back(row);
                answer.push_back(col);
            }
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int b = 24;
    int y = 24;

    vector<int> res = solution(b, y);
    for(auto& e : res) {
        cout << e << " ";
    }

    return 0;
}


