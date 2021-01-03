#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, string> users; // 유저 ID에 최신 닉네임 저장
vector<string> solution(vector<string> record) {
    vector<pair<string, string> > ordered;
    vector<string> answer;
    string infor[3];
    string temp = "";
    int count = 0;
    for (int i = 0; i < record.size(); i++) {
        temp = "";
        count = 0;
        for (int j = 0; j < record[i].length(); j++) {
            if (record[i][j] == ' ') {
                infor[count++] = temp;
                temp = "";
                continue;
            }
            temp += record[i][j];
        }
        infor[count++] = temp;
        if (infor[0].compare("Enter") == 0) {
            users[infor[1]] = infor[2];
            ordered.push_back(make_pair(infor[0], infor[1]));
        }
        else if (infor[0].compare("Change") == 0) {
            users[infor[1]] = infor[2];
        }
        else if (infor[0].compare("Leave") == 0) {
            ordered.push_back(make_pair(infor[0], infor[1]));
        }
    }
    for (int i = 0; i < ordered.size(); i++) {
        if (ordered[i].first.compare("Enter") == 0) {
            answer.push_back(users[ordered[i].second] + "님이 들어왔습니다.");
        }
        else if (ordered[i].first.compare("Leave") == 0) {
            answer.push_back(users[ordered[i].second] + "님이 나갔습니다.");
        }
    }
    return answer;
}