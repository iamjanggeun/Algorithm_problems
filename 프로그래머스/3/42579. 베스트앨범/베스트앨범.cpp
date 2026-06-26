#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

bool compareGenres(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

bool compareSongs(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {

    vector<int> answer;
    unordered_map<string, int> countGenres;
    unordered_map<string, vector<pair<int, int>>> countSongs;
    for(int i = 0; i < genres.size(); i++) {
        countGenres[genres[i]] += plays[i];
        countSongs[genres[i]].push_back({plays[i], i});
    }

    vector<pair<string, int>> sortedGenres(countGenres.begin(), countGenres.end());
    sort(sortedGenres.begin(), sortedGenres.end(), compareGenres);

    for(const auto& e : sortedGenres) {
        string genre = e.first;
        vector<pair<int, int>> songInfo = countSongs[genre];
        sort(songInfo.begin(), songInfo.end(), compareSongs);

        for(int i = 0; i < songInfo.size() && i < 2; i++) {
            answer.push_back(songInfo[i].second);
        }
    }

    return answer;
}