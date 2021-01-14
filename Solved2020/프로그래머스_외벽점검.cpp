#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#define INF 9999999
#define MINI(A,B) A>B ? B : A
using namespace std;
int dis[200], n_size, p_size;
int board[200], people[10];
stack<int> s_check;
bool flag = false;
int answer = INF;
bool checking() {
    int open_count = 0, pop_count = 0;
    int temp = 0;
    vector<int> check_dis;
    for (int i = 0; i < n_size; i++) {
        if (board[i] == 0) {
            s_check.push(dis[i]);
            if (open_count == 1) {
                pop_count++;
            }
        }
        else {
            open_count++;
            if (open_count == 2) {
                temp = 0;
                for (int j = 0; j < pop_count; j++) {
                    temp += s_check.top();
                    s_check.pop();
                }
                if (temp != 0) check_dis.push_back(temp);
                open_count = 1;
                pop_count = 0;
            }
        }
    }
    temp = 0;
    while (!s_check.empty()) {
        temp += s_check.top();
        s_check.pop();
    }
    if (temp != 0) check_dis.push_back(temp);
    sort(check_dis.begin(), check_dis.end());
    int left = 0, right = 0;
    for (int i = 0; i < check_dis.size(); i++) {
        while (true) {
            if (check_dis[i] <= people[right]) {
                right++;
                break;
            }
            else {
                right++;
            }
            if (right >= p_size) return false;
        }
    }
    return true;
}
void DFS(int vertex, int picked, int count, int limits) {
    if (flag) return;
    if (vertex >= 0) {
        if (picked == 1) board[vertex] = 1;
        else board[vertex] = 0;
        if (n_size - 1 - vertex + count < limits) return;
        if (count > limits) return;
    }
    if (vertex == n_size - 1) {
        if (checking()) {
            flag = true;
            answer = MINI(answer, limits);
        }
        return;
    }
    DFS(vertex + 1, 0, count, limits);
    DFS(vertex + 1, 1, count + 1, limits);
}
int solution(int n, vector<int> weak, vector<int> dist) {
    n_size = weak.size();
    p_size = dist.size();
    for (int i = 1; i < n_size; i++) {
        dis[i - 1] = weak[i] - weak[i - 1];
    }
    sort(dist.begin(), dist.end());
    for (int i = 0; i < p_size; i++) {
        people[i] = dist[i];
    }
    dis[n_size - 1] = weak[0] + n - weak[n_size - 1];
    int start = 1, end = p_size, mid;
    while (start <= end) {
        mid = (start + end) / 2;
        flag = false;
        DFS(-1, 0, 0, mid);
        if (!flag) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    if (answer == INF) answer = -1;
    return answer;
}