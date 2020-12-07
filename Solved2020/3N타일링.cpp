#include <string>
#include <vector>

using namespace std;
long long Dy[5002];
int solution(int n) {
    int answer = 0;
    Dy[0] = 1;
    for (int i = 2; i <= n; i += 2) {
        Dy[i] = Dy[i - 2] * 3;
        for (int j = 4; j <= i; j += 2) {
            Dy[i] += Dy[i - j] * 2;
        }
        Dy[i] %= 1000000007;
    }
    answer = Dy[n];
    return answer;
}