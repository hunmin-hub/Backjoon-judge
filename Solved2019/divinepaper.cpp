#include<stdio.h>
#define MAX 130
int paper[MAX][MAX];
int one, zero;
int N;
int checking(int x1, int y1, int x2, int y2)
{
	int flag = paper[x1][y1];
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (flag != paper[i][j]) return -1;
		}
	}
	return paper[x1][y1];
}
int divine(int x1,int y1,int x2,int y2)
{
	int temp = checking(x1, y1, x2, y2);
	if (temp != -1) {
		if (temp == 1) one++;
		else if (temp == 0) zero++;
	}
	else {
		divine(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
		divine(x1, ((y1 + y2) / 2) + 1, (x1 + x2) / 2, y2);
		divine(((x1 + x2) / 2) + 1, y1, x2, (y1 + y2) / 2);
		divine(((x1 + x2) / 2) + 1, ((y1 + y2) / 2) + 1, x2, y2);
	}
	return 0;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	divine(1, 1, N, N);
	printf("%d\n%d", zero, one);
	return 0;
}