#include<iostream>
#include<string>
#include<vector>
#include<queue>
#define INF 9999
using namespace std;
queue<pair<int,int> > v_queue[10];
int p_x[4] = { 1,-1,0,0 };
int p_y[4] = { 0,0,1,-1 };
int N, M, P;
int dist[11],board[1002][1002];
int answer[10];
void solution() {
	bool flag = false;
	int c_x, c_y;
	int next_x, next_y,temp;
	while (true) {
		flag = false;
		for (int i = 1; i <= P; i++) {
			for (int k = 0; k < dist[i]; k++) {
				if (v_queue[i].empty()) break;
				temp = v_queue[i].size();
				for (int l = 0; l < temp; l++) {
					c_x = v_queue[i].front().first;
					c_y = v_queue[i].front().second;
					v_queue[i].pop();
					for (int j = 0; j < 4; j++) {
						next_x = c_x + p_x[j];
						next_y = c_y + p_y[j];
						if (next_x < 0 || next_x == N || next_y < 0 || next_y == M) continue;
						if (board[next_x][next_y] == 0) {
							flag = true;
							board[next_x][next_y] = i;
							v_queue[i].push(make_pair(next_x, next_y));
						}
					}
				}
			}
		}
		if (!flag) break;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] != INF) {
				answer[board[i][j]]++;
			}
		}
	}
	for (int i = 1; i <= P; i++) {
		printf("%d ", answer[i]);
	}
}
int main() {
	string temp[1002];
	cin >> N >> M >> P;
	for (int i = 0; i < P; i++) {
		cin >> dist[i + 1];
	}
	for (int i = 0; i < N; i++) {
		cin >> temp[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == '.') {
				board[i][j] = 0;
			}
			else if (temp[i][j] == '#') {
				board[i][j] = INF;
			}
			else {
				board[i][j] = temp[i][j]-'0';
				v_queue[board[i][j]].push(make_pair(i, j));
			}
		}
	}
	solution();
	return 0;
}