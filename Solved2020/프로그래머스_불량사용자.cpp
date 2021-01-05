#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<string, int> users_id; // 각 유저 마다 고유번호 부여
unordered_map<string, bool> visit_id;
unordered_map<string, bool> check_overlap;
vector<string> match_banned[10];
int answer = 0;
bool match_user_banned(string users, string banned) {
    if (users.length() == banned.length()) {
        for (int i = 0; i < users.length(); i++) {
            if (banned[i] == '*') continue;
            if (users[i] != banned[i]) return false;
        }
    }
    else {
        return false;
    }
    return true;
}
void DFS(int vertex, int size, string temp) {
    if (vertex == size) {
        sort(temp.begin(), temp.end());
        if (!check_overlap[temp]) {
            check_overlap[temp] = true;
            answer++;
        }
        return;
    }
    for (int i = 0; i < match_banned[vertex].size(); i++) {
        if (!visit_id[match_banned[vertex][i]]) {
            string before_path = temp;
            int user_number = users_id[match_banned[vertex][i]];
            temp += to_string(user_number);
            visit_id[match_banned[vertex][i]] = true;
            DFS(vertex + 1, size, temp);
            temp.clear();
            temp = before_path;
            visit_id[match_banned[vertex][i]] = false;
        }
    }
    return;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    for (int i = 0; i < user_id.size(); i++) {
        users_id[user_id[i]] = i + 1;
    }
    for (int i = 0; i < banned_id.size(); i++) {
        for (int j = 0; j < user_id.size(); j++) {
            if (match_user_banned(user_id[j], banned_id[i])) {
                match_banned[i].push_back(user_id[j]);
            }
        }
    }
    DFS(0, banned_id.size(), "");
    return answer;
}