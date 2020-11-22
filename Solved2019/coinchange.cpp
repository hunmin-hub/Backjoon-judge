#include<stdio.h>
#define MAX 102
int coin[MAX];
int Dy[10002];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &coin[i]);
	}
	Dy[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= coin[i]) {
				Dy[j] += Dy[j - coin[i]];
			}
		}
	}
	printf("%d", Dy[K]);
	return 0;
}