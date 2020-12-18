#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<string, vector<pair<int, int>>> map_plays; // �帣 �� ���� ���Ƚ��

unordered_map<string, int> map_genres; // �帣 �� �� ���Ƚ��
unordered_map<string, int>::iterator genres_it;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) { // �帣 �� ���Ƚ���� ���ٸ� ���� ��ȣ�� ���� �뷡 ���� ����
        return a.first > b.first;
    }
    return a.second < b.second; // ��������
}
bool comp_gen(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second; // ��������
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    pair<string, int> check_genres[102]; // �帣�� ������ 100�� �̸�
    int count = 0;
    for (int i = 0; i < genres.size(); i++) {
        map_genres[genres[i]] += plays[i];
        map_plays[genres[i]].push_back(pair(i, plays[i]));
    }
    for (genres_it = map_genres.begin(); genres_it != map_genres.end(); genres_it++) {
        check_genres[count].first = genres_it->first; // �帣 �̸�
        check_genres[count++].second = genres_it->second; // �帣 �� ���Ƚ��
    }
    sort(check_genres, check_genres + count, comp_gen); // ���� �뷡�� ���� ����� �帣 ���� (1)

    string total_genres;

    for (int i = 0; i < count; i++) {
        total_genres = check_genres[i].first;
        sort(map_plays[total_genres].begin(), map_plays[total_genres].end(), comp); // �帣 �� ���� ����� �뷡 ���� (2)
        for (int i = 0; i < 2; i++) {
            if (map_plays[total_genres].empty()) break; // �帣�� ���� ���� �ϳ���� �ϳ��ǰ ����
            answer.push_back(map_plays[total_genres].back().first);
            map_plays[total_genres].pop_back();
        }
    }
    return answer;
}