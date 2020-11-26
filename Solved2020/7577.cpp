#include<stdio.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define MAX 1011
int dis[50];
int x[MAX], y[MAX], c[MAX];
int K, N;

int main()
{
	scanf("%d %d", &K, &N);
	for (int i = 1; i <=N; i++) {
		scanf("%d %d %d", &x[i], &y[i], &c[i]);
		x[i] -= 1;
	}
	for (int i = 1; i <= K; i++) dis[i] = 999999;

	for (int i = 1; i <=K; i++) {
		for (int j = 0; j < K; j++) {
			if (dis[j] != 999999) dis[j + 1] = min(dis[j + 1], dis[j] + 1);
		}
		for (int j = 0; j < K; j++) {
			if (dis[j + 1] != 999999) dis[j] = min(dis[j], dis[j + 1]);
		}
		for (int j = 1; j <=N; j++) {
			if (dis[x[j]] != 999999) dis[y[j]] = min(dis[y[j]], dis[x[j]] + c[j]);
		}
		for (int j = 1; j <=N; j++) {
			if (dis[y[j]] != 999999) dis[x[j]] = min(dis[x[j]], dis[y[j]] - c[j]);
		}
	}
	if (dis[1] < 0) {
		printf("NONE");
		return 0;
	}
	for (int i = 1; i <= K; i++) {
		if (dis[i] - dis[i - 1] == 1) printf("#");
		else printf("-");
	}
	return 0;
}