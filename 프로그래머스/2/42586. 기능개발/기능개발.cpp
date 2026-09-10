#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days(progresses.size(), 0);
    for(int i = 0; i < progresses.size(); i++) {
        int left = 100 - progresses[i];
        int day = left / speeds[i];
        
        if(left % speeds[i] != 0) day++;
        days[i] = day;
    }
    
    int pivot = days[0];
    int cnt = 1;
    
    for(int i = 1; i < days.size(); i++) {
        if(days[i] > pivot) {
            answer.push_back(cnt);
            cnt = 1;
            pivot = days[i];
        }
        else if(days[i] <= pivot) cnt++;
    }
    
    answer.push_back(cnt);
    
    return answer;
}