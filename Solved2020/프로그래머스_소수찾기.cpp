#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define MAX 10000000
using namespace std;
bool sosu[MAX], visit[MAX];
int number[8];
int permu[8];
int N, answer;
void era() {
    sosu[1] = true; sosu[0] = true;
    for (int i = 2; i <= sqrt(MAX); i++) {
        for (int j = i * 2; j <= MAX; j += i) {
            if (sosu[j]) continue;
            sosu[j] = true;
        }
    }
}
void calc_permutation(int board[], int count) {
    int calc = 1;
    int num;
    sort(board, board + count);
    do {
        calc = 1; num = 0;

        for (int i = count - 1; i >= 0; i--) {
            num += board[i] * calc;
            calc *= 10;
        }
        if (!sosu[num] && !visit[num]) {
            answer++;
        }

        visit[num] = true;
    } while (next_permutation(board, board + count));
}
int make_permutation(int count, int size, int vertex, int used) {
    if (used == 1) {
        permu[count++] = number[vertex];
    }
    if (count == size) {
        calc_permutation(permu, count);
        return 0;
    }
    if (vertex + 1 < N) {
        make_permutation(count, size, vertex + 1, 0);
        make_permutation(count, size, vertex + 1, 1);
    }
    return 0;
}
int solution(string numbers) {
    N = numbers.length();
    era();
    for (int i = 0; i < N; i++) {
        number[i] = numbers[i] - '0';
    }
    sort(number, number + N);
    for (int i = 1; i <= N; i++) {
        make_permutation(0, i, 0, 0);
        make_permutation(0, i, 0, 1);
    }

    return answer;
}