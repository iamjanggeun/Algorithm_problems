#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Work {
    int duration;
    int createdAt;
    int taskNo;
    
    bool operator<(const Work& other) const {
        if(duration != other.duration) return duration > other.duration;
        if(createdAt != other.createdAt) return createdAt > other.createdAt;
        return taskNo > other.taskNo;
    }
};

int solution(vector<vector<int>> jobs) {
    
    priority_queue<Work> pq;
    sort(jobs.begin(), jobs.end());
    
    int time = 0;
    int totTime = 0;
    int count = 0;
    int n = jobs.size();
    int idx = 0;
    
    while(count < n) {
        while(idx < n && jobs[idx][0] <= time) {
            pq.push({jobs[idx][1], jobs[idx][0], idx});
            idx++;
        }
        
        if(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            
            time += cur.duration;
            totTime += time - cur.createdAt;
            count++;
        }
        else time = jobs[idx][0];
    }
    return totTime / n;
}