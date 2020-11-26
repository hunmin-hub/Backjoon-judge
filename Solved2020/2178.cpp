#include<stdio.h>
#include<queue>
using namespace std;
queue<int> path_x;
queue<int> path_y;
queue<int> dis;
#define MAX 105
int N, M;
char temp[MAX][MAX];
int map[MAX][MAX],step[MAX][MAX];
int move_x[4] = { 1,-1,0,0 };
int move_y[4] = { 0,0,-1,1 };
int visit[MAX][MAX];
int BFS(int x,int y,int d)
{
	visit[x][y] = 1;
	step[x][y] = d;
	if (x == N && y == M) return 0;
	for (int i = 0; i < 4; i++) {
		if(x + move_x[i] >= 1 && x + move_x[i] <= N && y + move_y[i] >= 1 && y + move_y[i] <= M) {
			if (map[x + move_x[i]][y + move_y[i]] != 0 && step[x + move_x[i]][y + move_y[i]] > step[x][y] + 1) {
				path_x.push(x + move_x[i]);
				path_y.push(y + move_y[i]);
				dis.push(step[x][y] + 1);
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &temp[i]);
	}
	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <=M; j++) {
			step[i][j] = 999999;
			map[i][j] = temp[i-1][j-1] - '0';
		}
	}
	BFS(1, 1, 1);
	while (!path_x.empty() && !path_y.empty() && !dis.empty()) {
		if(visit[path_x.front()][path_y.front()]==0) BFS(path_x.front(), path_y.front(), dis.front());
		path_x.pop();
		path_y.pop();
		dis.pop();
	}
	printf("%d", step[N][M]);
	return 0;
}