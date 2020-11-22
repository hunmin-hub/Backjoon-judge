#include<stdio.h>
#define MAX 202
int R, C, N;
char pan[MAX][MAX];
int burst()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (pan[i][j] == 79) {
				pan[i][j] = '.';
				if (pan[i + 1][j] != 79) {
					pan[i + 1][j] = '.';
				}
				if (pan[i - 1][j] != 79 && i-1>=0) {
					pan[i - 1][j] = '.';
				}
				if (pan[i][j - 1] != 79 && j-1>=0) {
					pan[i][j - 1] = '.';
				}
				if (pan[i][j + 1] != 79) {
					pan[i][j + 1] = '.';
				}
			}
		}
	}
	return 0;
}
int insert_bomb()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (pan[i][j] == '.') {
				pan[i][j] = '1';
			}
		}
	}
	return 0;
}
int upgrade_bomb()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (pan[i][j] == '1') {
				pan[i][j] = 79;
			}
		}
	}
	return 0;
}
void PRINT()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (pan[i][j] == '1') printf("O");
			else printf("%c", pan[i][j]);
		}
		printf("\n");
	}
}
int process()
{
	int time = 1;
	for (;;) {
		if (time == N) break;
		upgrade_bomb();
		insert_bomb(); // 2ÃÊ
		time++;
		if (time == N) break;
		burst(); // 3ÃÊ
		time++;
	}
	PRINT();
	return 0;
}
int main()
{
	scanf("%d %d %d", &R, &C, &N);
	for (int i = 0; i < R; i++) {
		scanf("%s", pan[i]);
	}
	process();
	return 0;
}