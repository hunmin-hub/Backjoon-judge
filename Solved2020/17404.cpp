#include<stdio.h>
#define MAX 1005
#define min(a,b) (((a) < (b)) ? (a) : (b))
int N;
int cost[MAX][3];
int Dy[MAX][3];
int dynamic(int start) // 시작색깔 / 0 = R / 1 = G / 2 = B
{
	int mini=1000*1000+1;
	Dy[0][start] = cost[0][start]; // 첫집 색깔 고정
	for (int i = 1; i < N; i++) {
		Dy[i][0] = min(Dy[i - 1][1], Dy[i - 1][2]) + cost[i][0];
		Dy[i][1] = min(Dy[i - 1][0], Dy[i - 1][2]) + cost[i][1];
		Dy[i][2] = min(Dy[i - 1][0], Dy[i - 1][1]) + cost[i][2];
	}
	for (int i = 0; i < 3; i++) {
		if (start != i) {
			mini = min(mini, Dy[N - 1][i]);
		}
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
	int answer=1000*1000+1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		clear();
		answer=min(answer,dynamic(i)); // 첫번째 집 색깔 부여
	}
	printf("%d", answer);
	return 0;
}