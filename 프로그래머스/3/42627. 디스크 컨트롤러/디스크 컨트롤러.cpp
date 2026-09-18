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
    int jobIndex = 0;
    int count = 0;
    int n = jobs.size();
    
    while(count < n) {
        while(jobIndex < n && jobs[jobIndex][0] <= time) {
            pq.push({jobs[jobIndex][1], jobs[jobIndex][0], jobIndex});
            jobIndex++;
        }
        
        if(!pq.empty()) {
            Work cur = pq.top();
            pq.pop();
            
            time += cur.duration;
            totTime += (time - cur.createdAt);
            count++;
        }
        else time = jobs[jobIndex][0];
    }
    
    return totTime / n;
}