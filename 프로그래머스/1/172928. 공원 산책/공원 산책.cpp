#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int nx, ny, x, y;

vector<int> solution(vector<string> p, vector<string> r) {
    vector<int> answer;

    for(int i = 0; i < p.size(); i++) {
        for(int j = 0; j < p[0].size(); j++) {
            if(p[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    for(auto e : r) {
        int cnt = 0;
        int dist = e[2] - '0'; 
        
        if(e[0] == 'E') {
            for(int i = 0; i < dist; i++) { 
                nx = x + dx[1];
                ny = y + dy[1];
                if(nx < 0 || nx >= p.size() || ny < 0 || ny >= p[0].size() || p[nx][ny] == 'X') {
                    for(int j = 0; j < cnt; j++) {
                        x -= dx[1];
                        y -= dy[1];
                    }
                    break;
                }
                x = nx;
                y = ny;
                cnt++;
            }
        }
        else if(e[0] == 'N') {
            for(int i = 0; i < dist; i++) { 
                nx = x + dx[0];
                ny = y + dy[0];
                if(nx < 0 || nx >= p.size() || ny < 0 || ny >= p[0].size() || p[nx][ny] == 'X') { 
                    for(int j = 0; j < cnt; j++) {
                        x -= dx[0];
                        y -= dy[0];
                    }
                    break;
                }
                x = nx;
                y = ny;
                cnt++;
            }
        }
        else if(e[0] == 'S') {
            for(int i = 0; i < dist; i++) { 
                nx = x + dx[2];
                ny = y + dy[2];
                if(nx < 0 || nx >= p.size() || ny < 0 || ny >= p[0].size() || p[nx][ny] == 'X') { 
                    for(int j = 0; j < cnt; j++) {
                        x -= dx[2];
                        y -= dy[2];
                    }
                    break;
                }
                x = nx;
                y = ny;
                cnt++;
            }
        }
        else if(e[0] == 'W') {
            for(int i = 0; i < dist; i++) {
                nx = x + dx[3];
                ny = y + dy[3];
                if(nx < 0 || nx >= p.size() || ny < 0 || ny >= p[0].size() || p[nx][ny] == 'X') { 
                    for(int j = 0; j < cnt; j++) {
                        x -= dx[3];
                        y -= dy[3];
                    }
                    break;
                }
                x = nx;
                y = ny;
                cnt++;
            }
        }
    }
    answer.push_back(x);
    answer.push_back(y);

    return answer;
}