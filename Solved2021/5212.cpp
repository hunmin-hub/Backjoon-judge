#include<iostream>
#define MAX 12
using namespace std;
int N, M;
string maps[MAX];
int p_x[4] = { 1,-1,0,0 };
int p_y[4] = { 0,0,1,-1 };
int min_x=MAX, min_y=MAX, max_x, max_y;
void solution() {
	int count,next_x, next_y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			count = 0;
			if (maps[i][j] != 'X') continue;
			for (int k = 0; k < 4; k++) {
				next_x = i + p_x[k];
				next_y = j + p_y[k];
				if (next_x < 0 || next_x == N || next_y < 0 || next_y == M) count++;
				else if (maps[next_x][next_y] == '.') count++;
			}
			if (count >= 3) maps[i][j] = '0';
			else if(maps[i][j]=='X') {
				if (min_x > i) min_x = i;
				if (min_y > j) min_y = j;
				if (max_x < i) max_x = i;
				if (max_y < j) max_y = j;
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> maps[i];
	}
	solution();
	for (int i = min_x; i <= max_x; i++) {
		for (int j = min_y; j <= max_y; j++) {
			if (maps[i][j] == '0') printf(".");
			else printf("%c", maps[i][j]);
		}
		printf("\n");
	}
	return 0;
}