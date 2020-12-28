#include <string>
#include <iostream>
#include <vector>
#define MINI(A,B) A>B ? B : A
using namespace std;
bool cursor[22];
int check = 1, N, filled = 0;
int greedy(int vertex, int step) {
    filled++;
    cursor[vertex] = false;
    if (filled == check) {
        return step;
    }
    int right = vertex + 1, right_count = 1;
    int left = vertex - 1, left_count = 1;
    for (;;) {
        if (right == N) right = 0;
        if (cursor[right]) {
            break;
        }
        else {
            right++;
            right_count++;
        }
    }
    for (;;) {
        if (left < 0) left = N - 1;
        if (cursor[left]) {
            break;
        }
        else {
            left--;
            left_count++;
        }
    }
    if (right_count > left_count) {
        return greedy(left, step + left_count);
    }
    else {
        return greedy(right, step + right_count);
    }
}
int solution(string name) {
    int answer = 0;
    char temp_A = 'A', temp_B;
    int move_right = 0, move_left = 0;
    N = name.length();
    for (int i = 1; i < N; i++) {
        if (name[i] != 'A') {
            cursor[i] = true;
            check++;
        }
    }
    for (int i = 0; i < N; i++) {
        temp_B = name[i];
        answer += MINI(temp_B - temp_A, (temp_A + 26) - temp_B);
    }
    answer += greedy(0, 0);
    return answer;
}