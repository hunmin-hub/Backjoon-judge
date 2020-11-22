#include<stdio.h>
#define MAX 66
int avi[MAX][MAX];
int N;
int checking(int x1, int y1, int x2, int y2)
{
	int flag = avi[x1][y1];
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (flag != avi[i][j]) return -1;
		}
	}
	return flag;
}
int divine(int x1, int y1, int x2, int y2)
{
	int mid_x = (x1 + x2) / 2;
	int mid_y = (y1 + y2) / 2;
	int temp = checking(x1, y1, x2, y2);
	if (temp != -1) { // ¾ÐÃà
		printf("%d", temp);
	}
	else {
		printf("(");
		divine(x1, y1, mid_x, mid_y);
		divine(x1, mid_y + 1, mid_x, y2);
		divine(mid_x + 1, y1, x2, mid_y);
		divine(mid_x + 1, mid_y + 1, x2, y2);
		printf(")");
	}
	return 0;
}
int main()
{
	char tstr[MAX];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", tstr);
		for (int j = 1; j <= N; j++) {
			avi[i][j] = tstr[j-1] - '0';
		}
	}
	divine(1, 1, N, N);
	return 0;
}