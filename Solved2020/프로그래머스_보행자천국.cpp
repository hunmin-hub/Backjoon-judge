#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;
int Dy[505][505];
int board[505][505];
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
void init(int m, int n, vector<vector<int> > city_map) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = city_map[i][j];
            Dy[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        if (city_map[i][0] == 0) Dy[i][0] = 1;
        if (city_map[i][0] == 1) break;
    }
    for (int i = 0; i < n; i++) {
        if (city_map[0][i] == 0) Dy[0][i] = 1;
        if (city_map[0][i] == 1) break;
    }
}
int path_calc(int x, int y) {
    int count = 1;
    int sum_A = 0, sum_B = 0, sum = 0;
    while (x - count >= 0) {
        if (board[x - count][y] == 1) break;
        if (board[x - count][y] == 0) {
            sum_A = Dy[x - count][y];
            break;
        }
        count++;
    }
    sum_A %= MOD;
    count = 1;
    while (y - count >= 0) {
        if (board[x][y - count] == 1) break;
        if (board[x][y - count] == 0) {
            sum_B = Dy[x][y - count];
            break;
        }
        count++;
    }
    sum_B %= MOD;
    sum = (sum_A + sum_B) % MOD;
    return sum;
}
int solution(int m, int n, vector<vector<int> > city_map) {
    int answer = 0;
    init(m, n, city_map);
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (city_map[i][j] == 0) {
                Dy[i][j] = path_calc(i, j);
            }
        }
    }
    answer = Dy[m - 1][n - 1];
    return answer;
}