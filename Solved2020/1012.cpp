#include<stdio.h>
#define MAX 55
int maps[MAX][MAX];
int bugs[MAX][MAX];
int visit[MAX][MAX];
int n, m;
int cx[4] = { 0,0,1,-1 };
int cy[4] = { 1,-1,0,0 };
int searching(int x, int y,int bug)
{
	if (visit[x][y] == 1 || maps[x][y] == 0) {
		return 0;
	}
	else {
		visit[x][y] = 1;
		bugs[x][y] = bug;
		for (int i = 0; i < 4; i++) {
			if (visit[x + cx[i]][y + cy[i]] == 0 && maps[x + cx[i]][y + cy[i]] == 1) {
				searching(x + cx[i], y + cy[i], bug);
			}
		}
	}
	return 0;
}
int process()
{
	int count = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0 && maps[i][j] == 1) {
				searching(i,j,count++);
			}
		}
	}
	return count-1;
}
int clear()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maps[i][j] = 0;
			visit[i][j] = 0;
			bugs[i][j] = 0;
		}
	}
	return 0;
}
int main()
{
	int T,p,x,y;
	scanf("%d", &T);
	for (int k = 0; k < T; k++) {
		scanf("%d %d %d", &n, &m, &p);
		for (int i = 0; i < p; i++) {
			scanf("%d %d", &x, &y);
			maps[x][y] = 1;
		}
		printf("%d\n",process());
		clear();
	}
	return 0;
}