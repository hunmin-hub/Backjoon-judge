#include<stdio.h>
#define MAX 1002
int role[12];
int result[12];
char pan[MAX][MAX];
int starting[MAX][2];
int N, M, P;
int step(int x,int y,char player,int s,int count)
{
	if (x < 0 || y < 0) return 0;
	if (pan[x][y] == '#') return 0;
	if(pan[x][y]=='.') pan[x][y] = player;
	if (s >= count + 1) {
		step(x + 1, y, player, s, count + 1);
		step(x - 1, y, player, s, count + 1);
		step(x, y + 1, player, s, count + 1);
		step(x, y - 1, player, s, count + 1);
	}
	return 0;
}
void PRINT()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			result[pan[i][j] - '0']++;
		}
	}
	for (int i = 1; i <=P; i++) {
		printf("%d ", result[i]);
	}
}
int empty_check()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (pan[i][j] == '.') return 1;
		}
	}
	return 0;
}
int process()
{
	int count = 0;
	int x, y;
	for (;;) {
		if (empty_check() == 0) break;
		for (int k = 1; k <= P; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (pan[i][j] == '0' + k) {
						starting[count][0] = i;
						starting[count][1] = j;
						count++;
					}
				}
			}
			for (int i = 0; i < count; i++) {
				x = starting[i][0];
				y = starting[i][1];
				step(x, y, pan[x][y], role[k - 1], 0);
			}
			count = 0;
		}
	}
	PRINT();
	return 0;
}
int main()
{
	scanf("%d %d %d", &N, &M, &P);
	for (int i = 0; i < P; i++) {
		scanf("%d", &role[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", pan[i]);
	}
	process();
	return 0;
}