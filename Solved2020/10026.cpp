#include<stdio.h>
#define MAX 105
int visit[MAX][MAX];
int map1[MAX][MAX]; // 일반맵
int map2[MAX][MAX]; // 적록색약에서 본 맵
char temp[MAX][MAX];
int N;
int searching(int maps[][MAX],int x, int y, int flag,int counting)
{
	if (x<0 || y<0 || x>=N || y>=N) return 0;
	if (maps[x][y] == flag && visit[x][y]==0) {
		visit[x][y] = counting;
		searching(maps, x + 1, y, flag,counting); // 상
		searching(maps, x - 1, y, flag,counting); // 하
		searching(maps, x , y + 1, flag,counting); // 우
		searching(maps, x , y - 1, flag,counting); // 좌
	}
	return 0;
}
int main()
{
	int count = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", temp[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (temp[i][j] == 'R') {
				map1[i][j] = 1;
				map2[i][j] = 1;
			}
			else if (temp[i][j] == 'G') {
				map1[i][j] = 2;
				map2[i][j] = 1;
			}
			else if (temp[i][j] == 'B') {
				map1[i][j] = 3;
				map2[i][j] = 3;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map1[i][j]!=0 && visit[i][j] == 0) {
				searching(map1, i, j, map1[i][j], count);
				count++;
			}
		}
	}
	printf("%d ", count-1);
	count = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map2[i][j] != 0 && visit[i][j] == 0) {
				searching(map2, i, j, map2[i][j], count);
				count++;
			}
		}
	}
	printf("%d", count-1);
	return 0;
}