#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<string, vector<string> > city;
unordered_map<string, vector<string> >::iterator it;
int total_ticket, by_count;
vector<string> answer;
vector<string> temp_path;
bool flag = false;
bool comp(string& A, string& B) {
    if (A[0] == B[0]) {
        if (A[1] == B[1]) return A[2] < B[2];
        return A[1] < B[1];
    }
    return A[0] < B[0];
}
void DFS(string vertex, int count) {
    if (flag) return;
    temp_path.push_back(vertex);
    if (count == total_ticket) {
        flag = true; // 제일 처음 찾은 경로가 사전순으로 가장 빠른 경로
        answer = temp_path;
        temp_path.pop_back();
        return;
    }
    for (int i = 0; i < city[vertex].size(); i++) {
        string next_city = city[vertex].front();
        city[vertex].erase(city[vertex].begin());
        DFS(next_city, count + 1);
        city[vertex].push_back(next_city);
    }
    temp_path.pop_back();
    return;
}
vector<string> solution(vector<vector<string>> tickets) {

    total_ticket = tickets.size();
    for (int i = 0; i < tickets.size(); i++) {
        city[tickets[i][0]].push_back(tickets[i][1]);
    }
    for (it = city.begin(); it != city.end(); it++) {
        sort(it->second.begin(), it->second.end(), comp);
    }
    DFS("ICN", 0);
    return answer;
}