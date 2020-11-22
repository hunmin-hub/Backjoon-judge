#include<stdio.h>
#define MAX 1000002
int D[MAX];
int dynamic(int N)
{
	D[1] = 1;
	D[2] = 2;
	if (N <= 2) return 0;
	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + D[i - 2])%15746;
	}
	return 0;
}
int main()
{
	int N;
	scanf("%d", &N);
	dynamic(N);
	printf("%d", D[N]);
	return 0;
}