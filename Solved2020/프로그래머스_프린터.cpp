#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, int>> printer;
    for (int i = 0; i < priorities.size(); i++) {
        printer.push_back(make_pair(priorities[i], i));
    }
    while (!printer.empty()) {
        bool flag = true;
        int current_dis = printer.front().first;
        int current_idx = printer.front().second;
        //cout<<"("<<current_dis<<","<<current_idx<<")";
        for (int i = 1; i < printer.size(); i++) {
            if (current_dis < printer[i].first) {
                //cout<<"!";
                printer.erase(printer.begin());
                printer.push_back(make_pair(current_dis, current_idx));
                flag = false;
                break;
            }
        }
        if (flag) {
            answer++;
            printer.erase(printer.begin());
            if (current_idx == location) return answer;
        }
    }
    return answer;
}