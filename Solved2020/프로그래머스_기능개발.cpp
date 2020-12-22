#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int days = 0;
    while (!progresses.empty()) {
        days = 0;
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        while (progresses.front() >= 100) {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            days++;
            if (progresses.empty()) break;
        }
        if (days >= 1) {
            answer.push_back(days);
        }
    }
    return answer;
}