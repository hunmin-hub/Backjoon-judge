#include<stdio.h>
#define MAX 11
int coin[MAX];
int N, K;
int grid(int money)
{
	int count = 0;
	for (int i = N - 1; i >= 0;i--) {
		if (money == 0) break;
		for (;;) {
			if (money - coin[i] < 0) {
				break;
			}
			else {
				money -= coin[i];
				count++;
			}
		}
	}
	return count;
}
int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &coin[i]);
	}
	printf("%d", grid(K));
	return 0;
}