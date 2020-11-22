#include<stdio.h>
#define MAX 10002
int Dy[MAX];
int coin[102];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &coin[i]);
	}
	for (int i = 1; i <= MAX - 1; i++) {
		Dy[i] = 100002;
	}
	Dy[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			if (Dy[j] > Dy[j - coin[i]] + 1) {
				Dy[j] = Dy[j - coin[i]] + 1;
			}
		}
	}
	if (Dy[K] == 100002) printf("-1");
	else printf("%d", Dy[K]);
	return 0;
}