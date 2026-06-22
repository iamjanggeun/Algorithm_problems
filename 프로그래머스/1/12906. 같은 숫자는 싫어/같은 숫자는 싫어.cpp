#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) {
    stack<int> s;
    vector<int> answer;
    for(auto e : arr) {
        if(s.empty()) s.push(e);
        else if(!s.empty() && s.top() == e) continue;
        else if(!s.empty() && s.top() != e) {
            answer.push_back(s.top());
            s.pop();
            s.push(e);
        }
    }

    while(!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    
    return answer;
}