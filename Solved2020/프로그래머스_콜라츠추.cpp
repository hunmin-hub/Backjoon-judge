#include <string>
#include <vector>

using namespace std;
int Collatz(long long n, int count) {
    if (count == 500) return -1;
    if (n == 1) return count;
    else {
        if (n % 2 == 0) return Collatz(n / 2, count + 1);
        else return Collatz(n * 3 + 1, count + 1);
    }
}
int solution(int num) {
    int answer = 0;
    answer = Collatz(num, 0);
    return answer;
}