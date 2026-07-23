#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isYellow(int t, int G, int Y, int R) {
    int T = G + Y + R;
    int cycle = t % T;
    return ((G <= cycle) && (cycle < G + Y));
}

int solution(vector<vector<int>> signals) {
    
    int max_time = 1;
    for(auto& e : signals) {
        max_time *= (e[0] + e[1] + e[2]);
    }

    for(int t = 0; ;t++) {
        int yellowCnt = 0;
        for(auto& e : signals) {
            int G = e[0], Y = e[1], R = e[2];
            if(isYellow(t, G, Y, R)) yellowCnt++;
        }
        if(yellowCnt == signals.size()) return t + 1;
        if(t > max_time) return -1;
    }
}