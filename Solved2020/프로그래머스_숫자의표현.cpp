#include <string>
#include <vector>

using namespace std;
int backtrack(int number, int sum, int target) {
    if (sum == target) {
        return 1;
    }
    if (sum > target) return 0;
    return backtrack(number + 1, sum + number, target);
}
int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += backtrack(i, 0, n);
    }
    return answer;
}