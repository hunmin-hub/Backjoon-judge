#include <string>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> board;
int zero_sum, one_sum;
int N;
int check(int x1, int y1, int x2, int y2) {
    int stan = board[y1][x1];
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            if (board[i][j] != stan) return 2;
        }
    }
    return stan;
}
void fractal(int x1, int y1, int x2, int y2, int N) {
    int temp = check(x1, y1, x2, y2);
    if (temp != 2) {
        if (temp == 0) zero_sum++;
        else one_sum++;
        return;
    }
    fractal(x1, y1, x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2, N / 2);
    fractal(x1 + (x2 - x1) / 2 + 1, y1, x2, y1 + (y2 - y1) / 2, N / 2);
    fractal(x1, y1 + (y2 - y1) / 2 + 1, x1 + (x2 - x1) / 2, y2, N / 2);
    fractal(x1 + (x2 - x1) / 2 + 1, y1 + (y2 - y1) / 2 + 1, x2, y2, N / 2);
    return;
}
vector<int> solution(vector<vector<int>> arr) {
    board = arr;
    N = arr.size();
    fractal(0, 0, N - 1, N - 1, N);
    vector<int> answer;
    answer.push_back(zero_sum);
    answer.push_back(one_sum);
    return answer;
}