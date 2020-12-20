#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MINI(A,B) A>B ? B : A
using namespace std;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long end_time = (long long)times[times.size() - 1];
    end_time *= n;
    long long start_time = 1, mid_time;
    long long check_able;
    answer = end_time;
    while (start_time <= end_time) {
        mid_time = (start_time + end_time) / 2;
        check_able = 0;
        // check
        for (int i = 0; i < times.size(); i++) {
            check_able += mid_time / times[i];
        }
        if (check_able < n) {
            start_time = mid_time + 1;
        }
        else {
            answer = MINI(answer, mid_time);
            end_time = mid_time - 1;
        }
    }
    return answer;
}