#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mp;
    
    for(auto e : participant) mp[e]++;
    for(auto e : completion) mp[e]--;
    for(auto e : mp) {
        if(e.second > 0) answer = e.first;
    }
    
    return answer;
}