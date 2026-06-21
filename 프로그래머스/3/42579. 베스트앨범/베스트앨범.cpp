#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool compare_genres(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

bool compare_songs(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map <string, int> genre_cnt;
    unordered_map <string, vector<pair<int,int>>> songs_in_genre;

    for(int i = 0; i < genres.size(); i++) {
        genre_cnt[genres[i]] += plays[i];
        songs_in_genre[genres[i]].push_back({plays[i], i});
    }

    vector<pair<string, int>> sorted_genre(genre_cnt.begin(), genre_cnt.end());
    sort(sorted_genre.begin(), sorted_genre.end(), compare_genres);

    for(auto e : sorted_genre) {
        string genre_name = e.first;
        vector<pair<int, int>> song_info = songs_in_genre[genre_name];
        
        sort(song_info.begin(), song_info.end(), compare_songs);

        for(int i = 0; i < song_info.size() && i < 2; i++) {
            answer.push_back(song_info[i].second);
        }
    }
    return answer;
}