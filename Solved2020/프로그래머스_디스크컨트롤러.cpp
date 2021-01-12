#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct compA {
    bool operator()(pair<int, int> A, pair<int, int> B) {
        if (A.first == B.first) {
            return A.second > B.second;
        }
        return A.first > B.first;
    }
};
struct compB {
    bool operator()(pair<int, int> A, pair<int, int> B) {
        return A.second > B.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, compA> disk;
priority_queue<pair<int, int>, vector<pair<int, int> >, compB> temp_disk;
int solution(vector<vector<int>> jobs) {
    int answer = 0, count = 0;
    bool flag = true;
    for (int i = 0; i < jobs.size(); i++) {
        disk.push(make_pair(jobs[i][0], jobs[i][1]));
    }
    int current_time = disk.top().first + disk.top().second;
    answer += disk.top().second;
    disk.pop();
    while (!disk.empty()) {
        flag = false;
        while (!disk.empty()) {
            if (current_time < disk.top().first) break;
            flag = true;
            temp_disk.push(make_pair(disk.top().first, disk.top().second));
            disk.pop();
        }
        if (flag) {
            answer += ((current_time - temp_disk.top().first) + temp_disk.top().second);
            current_time += temp_disk.top().second;
            temp_disk.pop();
            while (!temp_disk.empty()) {
                disk.push(make_pair(temp_disk.top().first, temp_disk.top().second));
                temp_disk.pop();
            }
        }
        else {
            answer += disk.top().second;
            current_time = disk.top().first + disk.top().second;
            disk.pop();
        }
    }
    answer /= jobs.size();
    return answer;
}