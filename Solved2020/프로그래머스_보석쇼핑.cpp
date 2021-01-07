#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#define INF 9999999
using namespace std;
unordered_map<string, int> have_gems;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int all_gems;
    int N = gems.size();
    int left = 0, right = 0;
    int answer_gap = INF, answer_left, answer_right;
    for (int i = 0; i < N; i++) {
        if (have_gems[gems[i]] == 0) {
            have_gems[gems[i]]++;
        }
    }
    all_gems = have_gems.size(); // 최대 보석 종류
    have_gems.clear();
    have_gems[gems[0]]++;

    while (left <= N - 1 && right <= N - 1) {
        if (have_gems.size() == all_gems) {
            if (answer_gap > right - left) {
                answer_gap = right - left;
                answer_left = left + 1;
                answer_right = right + 1;
            }
            have_gems[gems[left]]--;
            if (have_gems[gems[left]] == 0) {
                have_gems.erase(gems[left]);
            }
            left++;
        }
        else {
            right++;
            if (right > N - 1) continue;
            have_gems[gems[right]]++;
        }
    }
    answer.push_back(answer_left);
    answer.push_back(answer_right);
    return answer;
}