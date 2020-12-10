#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    bool check = false;
    for (int i = begin; i <= end; i++) {
        if (i == 1) {
            answer.push_back(0);
            continue;
        }
        check = false;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0 && i / j <= 10000000) {
                check = true;
                answer.push_back(i / j);
                break;
            }
        }
        if (!check) answer.push_back(1);
    }
    return answer;
}