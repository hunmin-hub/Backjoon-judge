#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int, int> > numbers; // first : value / second : idx
vector<pair<int, int> >::iterator it;
int ori_numbers[1000002]; // 원본
bool use_num[1000002];
bool comp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
string solution(string number, int k) {
    string answer = "";
    int N = number.length();
    int current_idx = 0;
    int count = 0;
    int big_num, big_idx;
    for (int i = 0; i < N; i++) {
        ori_numbers[i] = number[i] - '0';
        numbers.push_back(make_pair(number[i] - '0', i));
    }
    sort(numbers.begin(), numbers.end(), comp);
    it = numbers.begin();
    while (k > 0) {
        if (current_idx == N) break;
        for (int i = 0; i < numbers.size(); i++) {
            big_num = numbers[i].first; // 큰 수 앞자리
            big_idx = numbers[i].second;
            if (big_idx < current_idx) continue;
            if (big_idx - current_idx <= k) {
                k -= (big_idx - current_idx);
                current_idx = big_idx + 1;
                answer += (big_num + '0');
                numbers.erase(it + i);
                break;
            }
        }
    }
    for (int i = current_idx; i < N; i++) {
        answer += (ori_numbers[i] + '0');
    }
    answer.erase(answer.end() - k, answer.end());
    return answer;
}