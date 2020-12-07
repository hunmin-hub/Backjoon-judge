#include <string>
#include <vector>

using namespace std;
int current_stage[502], check[502];
double fail[502];
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int user = stages.size();
    double max = -1;
    int max_stage = 0;

    for (int i = 0; i < user; i++) {
        current_stage[stages[i]]++;
    }
    for (int i = 1; i <= N; i++) {
        if (user == 0) fail[i] = 0;
        else fail[i] = double(current_stage[i]) / double(user);
        fail[i] *= 100.0;
        user -= current_stage[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (check[j] == 0 && max < fail[j]) {
                max = fail[j];
                max_stage = j;
            }
        }
        check[max_stage] = 1;
        answer.push_back(max_stage);
        max = -1;
    }
    return answer;
}