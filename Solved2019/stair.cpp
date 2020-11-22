#include<stdio.h>
#define MAX_MAC(a, b) (((a)>(b))?(a):(b))
#define MAX 302
int stair[MAX];
int dy[3][MAX];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &stair[i]);
	}
	for (int i = 1; i <= N; i++) {
		dy[1][i] = MAX_MAC(dy[1][i - 2], dy[2][i - 2]) + stair[i];
		dy[2][i] = dy[1][i - 1]+stair[i];
	}
	printf("%d", MAX_MAC(dy[1][N], dy[2][N]));
	return 0;
}