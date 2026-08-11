#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    if(startday == 7) startday = 0;
    
    for(int i = 0; i < schedules.size(); i++) {
        bool flag = true;
        
        int hour = schedules[i] / 100;
        int minute = schedules[i] % 100 + 10;
        
        if (minute >= 60) {
            minute -= 60;
            hour += 1;
        }
        
        int limit = hour * 100 + minute;
        int temp = startday;
        
        for(auto e : timelogs[i]) {
            int day = temp % 7;
            temp++;
            if(day == 0 || day == 6) continue;
            if(e > limit) flag = false;
        }
        if(flag) answer++;
    }
    return answer;
}