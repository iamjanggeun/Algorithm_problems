#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    // record 문자열 파싱
    map<string, vector<int>> mp;
    
    for(int i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);
        string timeStr, carNum, status;
        
        ss >> timeStr >> carNum >> status;
        
        int time = stoi(timeStr.substr(0, 2)) * 60 + stoi(timeStr.substr(3, 2));
        mp[carNum].push_back(time);
    }
    
    for(const auto& e : mp) {
        vector<int> timeList = e.second;
        if(timeList.size() % 2 != 0) timeList.push_back(1439);
        int parkingTime = 0;
        int totFee = fees[1];
        int extraTime = 0;
        
        for(int i = 0; i < timeList.size(); i+=2) {
            parkingTime += timeList[i + 1] - timeList[i];
        }
        
        if(parkingTime > fees[0]) {
            extraTime = parkingTime - fees[0];
            totFee += ((extraTime + fees[2] - 1) / fees[2]) * fees[3];
        }
        
        answer.push_back(totFee);
    }
    return answer;
}