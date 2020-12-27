#include <iostream>
using namespace std;
int jump(int n, int cost) {
    if (n == 0) return cost;
    if (n % 2 == 0) {
        return jump(n / 2, cost);
    }
    else {
        return jump(n - 1, cost + 1);
    }
}
int solution(int n)
{
    int ans = 0;
    ans = jump(n, 0);
    return ans;
}