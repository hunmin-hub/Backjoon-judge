#include <string>
#include <vector>
#include <iostream>
#define MINI(A,B) A>B ? B : A
using namespace std;
int N;
int p_x[4] = { 0,0,1,-1 };
int p_y[4] = { 1,-1,0,0 };
bool visit[30][30];
int answer = 99999999;
void DFS(int x, int y, int r_case, int cost) {
    if (cost >= answer) return;
    printf("(%d,%d):%d[case:%d]\n", x, y, cost,r_case);
    // r_case : 1 좌->우 / 2 우->좌 / 3 위->아래 / 4 아래->위 / 5 출발점
    if (x == N - 1 && y == N - 1) {
        printf("도착---------%d\n", cost);
        answer = MINI(answer, cost);
        return;
    }
    int next_x, next_y;
    for (int i = 0; i < 4; i++) {
        next_x = x + p_x[i];
        next_y = y + p_y[i];
        if (next_x < 0 || next_x == N || next_y < 0 || next_y == N) continue;
        if (visit[next_x][next_y]) continue;
        if (r_case != i + 1 && r_case != 5) { // 커브를 만들어낸다면
            visit[next_x][next_y] = true;
            DFS(next_x, next_y, i+1, cost + 500);
            visit[next_x][next_y] = false;
        }
        else {
            visit[next_x][next_y] = true;
            DFS(next_x, next_y, i+1, cost + 100);
            visit[next_x][next_y] = false;
        }
    }
}
int solution(vector<vector<int>> board) {
    N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) visit[i][j] = true;
        }
    }
    visit[0][0] = true;
    DFS(0, 0, 5, 0);
    return answer;
}
int main() {
    vector<vector<int> > board;
    board.push_back({ 0,0,0 });
    board.push_back({ 0,0,0 });
    board.push_back({ 0,0,0 });
    solution(board);
    return 0;
}