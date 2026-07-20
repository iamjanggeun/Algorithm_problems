#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compareGenres(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

bool compareSongs(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> Genres, vector<int> Plays) {

    unordered_map<string, int> countGenre;
    unordered_map<string, vector<pair<int, int>>> SongInGenres;
    vector<int> ans;

    for(int i = 0; i < Genres.size(); i++) {
        countGenre[Genres[i]] += Plays[i];
        SongInGenres[Genres[i]].push_back({Plays[i], i});
    }

    //countGenre 정렬하기
    vector<pair<string, int>> sortedGenre(countGenre.begin(), countGenre.end());
    sort(sortedGenre.begin(), sortedGenre.end(), compareGenres);

    for(int i = 0; i < sortedGenre.size(); i++) {
        string genre = sortedGenre[i].first;
        vector<pair<int, int>> songInfo = SongInGenres[genre];
        sort(songInfo.begin(), songInfo.end(), compareSongs);
        for(int j = 0; j < 2 && j < songInfo.size(); j++) {
            ans.push_back(songInfo[j].second);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> g = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> p = {500, 600, 150, 800, 2500};
    vector<int> res = solution(g, p);

    for(auto e : res) cout << e << " ";

    return 0;
}