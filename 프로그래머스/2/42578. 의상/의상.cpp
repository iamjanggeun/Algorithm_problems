#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> mp;
    
    for(auto e : clothes) mp[e[1]]++;
    for(auto e : mp) answer *= e.second + 1;
    answer--;
    
    return answer;
}