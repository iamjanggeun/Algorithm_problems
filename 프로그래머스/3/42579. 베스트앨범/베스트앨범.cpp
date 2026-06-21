#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//장르 전체 내림차순
bool compareGenre(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

//장르 내 노래 내림차순
bool compareSong(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map <string, int> genre_cnt;
    unordered_map <string, vector<pair<int, int>>> songs;

    for(int i = 0; i < genres.size(); i++) {
        genre_cnt[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i], i});
    }

    vector<pair<string, int>> sorted_genre(genre_cnt.begin(), genre_cnt.end());
    sort(sorted_genre.begin(), sorted_genre.end(), compareGenre);

    for(auto e : sorted_genre) {
        string genreName = e.first;
        vector<pair<int, int>> a = songs[genreName];

        sort(a.begin(), a.end(), compareSong);

        for(int i = 0; i < a.size() && i < 2; i++) answer.push_back(a[i].second);
    }

    return answer;
}