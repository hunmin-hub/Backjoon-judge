#include<vector>
#include<math.h>
#include<iostream>
using namespace std;
#define MAXI(A,B) A>B ? A : B
int board[302][302];
int N;
int maxi_h = 0, mini_h = 1000000001;
void init(vector<vector<int> > land) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = land[i][j];
            maxi_h = MAXI(maxi_h, board[i][j]);
        }
    }
}
long long details(long long temp, int P, int Q) {
    long long num = 0;
    if (temp < 0) {
        num = (long long)(temp * P * (-1));
    }
    else {
        num = (long long)(temp * Q);
    }
    return num;
}
long long calc(int height, int P, int Q) {
    long long sum_left = 0, sum_mid = 0, sum_right = 0;
    long long temp1, temp2, temp3;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp1 = board[i][j] - (height - 1); // left
            temp2 = temp1 - 1; // mid
            temp3 = temp1 - 2; // right
            sum_left += details(temp1, P, Q);
            sum_mid += details(temp2, P, Q);
            sum_right += details(temp3, P, Q);
        }
    }
    if (sum_left >= sum_mid && sum_mid <= sum_right) return sum_mid; // 변곡점
    if (sum_left >= sum_mid && sum_mid >= sum_right) return (-2); // 감소 기울기
    if (sum_left <= sum_mid && sum_mid <= sum_right) return (-1); // 증가 기울기
}
long long solution(vector<vector<int> > land, int P, int Q) {
    long long answer;
    long long mid_c = 0;
    int start, end, mid;
    long long left, right;
    N = land.size();
    init(land);
    start = 0;
    end = maxi_h;
    while (start <= end) {
        mid = (start + end) / 2;
        mid_c = calc(mid, P, Q);
        if (mid_c == -2) {
            start = mid + 1;
        }
        else if (mid_c == -1) {
            end = mid - 1;
        }
        else {
            answer = mid_c;
            break;
        }
    }
    return answer;
}