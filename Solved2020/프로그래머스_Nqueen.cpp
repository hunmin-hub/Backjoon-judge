#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool c_x[25], c_y[25], c_left[25], c_right[25];
int mn, count;
void checking(int N, int i, bool c) {
    c_x[N + 1] = c;
    c_y[i] = c;
    c_left[N + i + 1] = c;
    c_right[N + 1 - i + mn] = c;
}
void DFS(int N) {
    if (N == mn) {
        count++;
        return;
    }
    for (int i = 1; i <= mn; i++) { // ÁÂÇ¥(N+1,i)
        if (!c_x[N + 1] && !c_y[i] && !c_left[N + i + 1] && !c_right[N + 1 - i + mn]) {
            checking(N, i, true);
            DFS(N + 1);
            checking(N, i, false);
        }
    }
}
int solution(int n) {
    mn = n;
    int answer = 0;
    DFS(0);
    answer = count;
    return answer;
}