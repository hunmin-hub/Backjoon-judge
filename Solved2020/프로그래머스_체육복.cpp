#include <string>
#include <vector>

using namespace std;
int have_student[32];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for (int i = 1; i <= n; i++) have_student[i] = 1;
    for (int i = 0; i < lost.size(); i++) have_student[lost[i]]--;
    for (int i = 0; i < reserve.size(); i++) have_student[reserve[i]]++;

    for (int i = 1; i <= n; i++) {
        if (have_student[i] == 0) {
            if (have_student[i - 1] == 2) {
                have_student[i - 1]--;
                have_student[i]++;
            }
            else if (have_student[i + 1] == 2) {
                have_student[i + 1]--;
                have_student[i]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (have_student[i] >= 1) answer++;
    }
    return answer;
}