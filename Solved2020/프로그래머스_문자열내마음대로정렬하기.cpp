#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int iter;
bool compare(string A, string B) {
    if (A[iter] != B[iter]) {
        return A[iter] < B[iter];
    }
    else {
        return A < B;
    }
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    iter = n;
    sort(strings.begin(), strings.end(), compare);
    answer.assign(strings.begin(), strings.end());
    return answer;
}