#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    
    map<string, vector<int>> mp;
    for(auto e : records) {
        stringstream ss(e);
        string timeStr, carNum, status;
        
        ss >> timeStr >> carNum >> status;
        
        int totTime = stoi(timeStr.substr(0,2)) * 60 + stoi(timeStr.substr(3, 2));
        
        mp[carNum].push_back(totTime);
    }
    
    vector<int> result;
    
    for(auto e : mp) {
        if(e.second.size() % 2 != 0) e.second.push_back(1439);
        
        int totParkingTime = 0;
        for(int i = 0; i < e.second.size(); i+=2) {
            totParkingTime += e.second[i + 1] - e.second[i];
        }
        
        int tempFee = fees[1];
        if(totParkingTime > fees[0]) {
            int addFee = (totParkingTime - fees[0] + fees[2] - 1) / fees[2];
            tempFee += addFee * fees[3];
        }
        
        result.push_back(tempFee);
    }
    
    return result;
}