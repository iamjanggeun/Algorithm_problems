#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dy[] = {-1, 1, 0, 0}; 
int dx[] = {0, 0, -1, 1};

vector<int> solution(vector<string> park, vector<string> routes) {
    int y = 0, x = 0;
    int H = park.size();
    int W = park[0].size();

    // 1. 시작 지점(S) 찾기
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(park[i][j] == 'S') {
                y = i;
                x = j;
            }
        }
    }

    // 2. 명령 수행
    for(auto e : routes) {
        char dir = e[0];
        int dist = e[2] - '0'; 
        
        int dir_idx = 0;
        if(dir == 'N') dir_idx = 0;
        else if(dir == 'S') dir_idx = 1;
        else if(dir == 'W') dir_idx = 2;
        else if(dir == 'E') dir_idx = 3;

        int ny = y;
        int nx = x;
        bool is_valid = true;

        for(int i = 0; i < dist; i++) {
            ny += dy[dir_idx];
            nx += dx[dir_idx];

            if(ny < 0 || ny >= H || nx < 0 || nx >= W || park[ny][nx] == 'X') {
                is_valid = false;
                break;
            }
        }

        if(is_valid) {
            y = ny;
            x = nx;
        }
    }

    return {y, x};
}