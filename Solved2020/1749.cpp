#include<stdio.h>
#define MAX 1005
#define min(a,b) (((a) < (b)) ? (a) : (b))
int N;
int cost[MAX][3];
int Dy[MAX][3];
int dynamic()
{
	int mini = 1000 * 1000 + 1;
	Dy[0][0] = cost[0][0];
	Dy[0][1] = cost[0][1];
	Dy[0][2] = cost[0][2];
	for (int i = 1; i < N; i++) {
		Dy[i][0] = min(Dy[i - 1][1], Dy[i - 1][2]) + cost[i][0];
		Dy[i][1] = min(Dy[i - 1][0], Dy[i - 1][2]) + cost[i][1];
		Dy[i][2] = min(Dy[i - 1][0], Dy[i - 1][1]) + cost[i][2];
	}
	for (int i = 0; i < 3; i++) {
		mini = min(mini, Dy[N - 1][i]);
	}
	return mini;
}
int clear()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			Dy[i][j] = 1000 * 1000 + 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	clear();
	printf("%d",dynamic());
	return 0;
}