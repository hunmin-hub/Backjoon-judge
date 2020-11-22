#include<stdio.h>
#define MAX 102
int N, M;
int block[MAX][MAX];
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", block[i][j]);
		}
	}
}