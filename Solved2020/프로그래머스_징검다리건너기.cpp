#include <string>
#include <vector>
#define MAXI(A,B) A>B ? A : B
using namespace std;
int board[200002];
int n_size;
bool checking(int n, int k) { // n명이 지나갈 수 있는 지 검사
    int count = 0;
    for (int i = 0; i < n_size; i++) {
        if (board[i] - n < 0) {
            count++;
            if (count == k) return false;
        }
        else {
            count = 0;
        }
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int start = 0, end, mid;
    bool flag;
    n_size = stones.size();
    for (int i = 0; i < n_size; i++) {
        end = MAXI(end, stones[i]);
        board[i] = stones[i];
    }
    while (start <= end) {
        mid = (start + end) / 2;
        flag = checking(mid, k);
        if (flag) {
            answer = MAXI(answer, mid);
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return answer;
}