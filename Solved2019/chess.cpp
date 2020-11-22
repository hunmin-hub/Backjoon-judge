#include<stdio.h>
#define MAX 51
char chess[MAX][MAX];
int visit[MAX][MAX];
int N, M;
int count = 0;
int mini = 2501;
int clear()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
	return 0;
}
int fill_check(int x, int y,int flag,int xc,int yc) // flag=1 °ËÁ¤ / flag=0 ¹é
{
	char temp = chess[x][y];
	if (x == N || y == M) return 0;
	if (xc == 8 || yc == 8) return 0;
	if (flag == 1 && chess[x][y] == 'W') {
		chess[x][y] = 'B';
		if (visit[x][y] == 0) count++;
		visit[x][y] = 1;
	}
	else if (flag == 0 && chess[x][y] == 'B') {
		chess[x][y] = 'W';
		if (visit[x][y] == 0) count++;
		visit[x][y] = 1;
	}
	if (chess[x][y] == 'B') {
		fill_check(x + 1, y, 0,xc+1,yc);
		fill_check(x, y + 1, 0,xc,yc+1);
	}
	else if (chess[x][y] == 'W') {
		fill_check(x + 1, y, 1,xc+1,yc);
		fill_check(x, y + 1, 1,xc,yc+1);
	}
	chess[x][y] = temp;
	return 0;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", chess[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(i+7<N && j+7<M) {
				clear();
				fill_check(i, j, 0, 0, 0);
				if (mini > count) mini = count;
				count = 0;
				clear();
				fill_check(i, j, 1, 0, 0);
				if (mini > count) mini = count;
				count = 0;
			}
		}
	}
	printf("%d", mini);
	return 0;
}