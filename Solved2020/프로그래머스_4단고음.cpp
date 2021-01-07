#include <iostream>
#include <algorithm>
using namespace std;
int board[100];
int solution(int n) {
    int answer = 0;
    int size, star_count = 0, plus_count = 0;
    while (n / 3 > 0) {
        n /= 3;
        star_count++;
    }
    plus_count = star_count * 2;
    size = plus_count + star_count;
    for (int i = plus_count; i < size; i++) {
        board[i] = 1;
    }
    int count = 0;
    do {
        count++;
    } while (next_permutation(board, board + size));
    cout << count << " ";
    return answer;
}
int main() {
    solution(2147483647);
    return 0;
}