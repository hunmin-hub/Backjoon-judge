#include <string>
#include <vector>
#include <iostream>
using namespace std;
int p_x[3] = { 1,1,0 };
int p_y[3] = { 0,1,1 };
char main_board[32][32];
bool next_bomb[32][32];
int M, N;
int bomb_count() {
    int count = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (next_bomb[i][j]) count++;
            next_bomb[i][j] = false;
        }
    }
    return count;
}
void clear_check(int x, int y) {
    if (x + 1 == M || y + 1 == N) return;
    for (int i = 0; i < 3; i++) {
        if (main_board[x][y] != main_board[x + p_x[i]][y + p_y[i]]) {
            return;
        }
    }
    next_bomb[x][y] = true;
    for (int i = 0; i < 3; i++) {
        next_bomb[x + p_x[i]][y + p_y[i]] = true;
    }
    return;
}
void down_block(int x, int y) {
    if (x == 0) return;
    main_board[x][y] = main_board[x - 1][y];
    main_board[x - 1][y] = -1;
    down_block(x - 1, y);
}
int turn_scan() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (main_board[i][j] != -1) {
                clear_check(i, j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (next_bomb[j][i]) main_board[j][i] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (main_board[j][i] == -1) {
                down_block(j, i);
            }
        }
    }
    return bomb_count();
}
int solution(int m, int n, vector<string> board) {
    M = m, N = n;
    int answer = 0, turn_score;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            main_board[i][j] = board[i][j];
        }
    }
    while (true) {
        turn_score = turn_scan();
        if (turn_score == 0) break;
        answer += turn_score;
    }
    return answer;
}