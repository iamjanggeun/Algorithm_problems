#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

bool compareGenre(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

bool compareSong(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> genreCount;
    unordered_map<string, vector<pair<int, int>>> songCount;

    //1. 장르, 재생수 맵핑
    for(int i = 0; i < genres.size(); i++) {
        genreCount[genres[i]] += plays[i];
        songCount[genres[i]].push_back({plays[i], i});
    }

    //2. 정렬 위해 맵핑 -> 벡터 복사
    vector<pair<string, int>> sortedGenre(genreCount.begin(), genreCount.end());
    sort(sortedGenre.begin(), sortedGenre.end(), compareGenre);

    //3. 정렬된 장르 안에서 장르 내 노래 정렬
    for(int i = 0; i < sortedGenre.size(); i++) {
        string genre = sortedGenre[i].first;  
        vector<pair<int, int>> songInfo = songCount[genre];
        sort(songInfo.begin(), songInfo.end(), compareSong);
        for(int j = 0; j < songInfo.size() && j < 2; j++) {
            answer.push_back(songInfo[j].second);
        }
    }

    return answer;
}