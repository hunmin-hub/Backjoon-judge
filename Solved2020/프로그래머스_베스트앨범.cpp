#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<string, vector<pair<int, int>>> map_plays; // 장르 내 각각 재생횟수

unordered_map<string, int> map_genres; // 장르 별 총 재생횟수
unordered_map<string, int>::iterator genres_it;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) { // 장르 내 재생횟수가 같다면 고유 번호가 낮은 노래 먼저 수록
        return a.first > b.first;
    }
    return a.second < b.second; // 오름차순
}
bool comp_gen(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second; // 내림차순
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    pair<string, int> check_genres[102]; // 장르의 종류는 100개 미만
    int count = 0;
    for (int i = 0; i < genres.size(); i++) {
        map_genres[genres[i]] += plays[i];
        map_plays[genres[i]].push_back(pair(i, plays[i]));
    }
    for (genres_it = map_genres.begin(); genres_it != map_genres.end(); genres_it++) {
        check_genres[count].first = genres_it->first; // 장르 이름
        check_genres[count++].second = genres_it->second; // 장르 총 재생횟수
    }
    sort(check_genres, check_genres + count, comp_gen); // 속한 노래가 많이 재생된 장르 수록 (1)

    string total_genres;

    for (int i = 0; i < count; i++) {
        total_genres = check_genres[i].first;
        sort(map_plays[total_genres].begin(), map_plays[total_genres].end(), comp); // 장르 내 많이 재생된 노래 수록 (2)
        for (int i = 0; i < 2; i++) {
            if (map_plays[total_genres].empty()) break; // 장르의 속한 곡이 하나라면 하나의곡만 선택
            answer.push_back(map_plays[total_genres].back().first);
            map_plays[total_genres].pop_back();
        }
    }
    return answer;
}