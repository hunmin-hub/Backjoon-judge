#include<stdio.h>
#define MAX 502
int rec[MAX][MAX];
int dy[MAX][MAX];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &rec[i][j]);
		}
	}
	int a, b;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			a=rec[i][j] + dy[i - 1][j];
			b=rec[i][j] + dy[i - 1][j - 1];
			if (a > b) dy[i][j] = a;
			else dy[i][j] = b;
		}
	}
	int maxi = 0;
	for (int i = 1; i <= N; i++) {
		if (maxi < dy[N][i]) maxi = dy[N][i];
	}
	printf("%d", maxi);
	return 0;
}