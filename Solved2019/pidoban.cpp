#include<stdio.h>
#define MAX 102
long long D[MAX];
int Dynamic(int N)
{
	D[1] = 1; D[2] = 1; D[3] = 1; D[4] = 2;
	D[5] = 2; D[6] = 3; D[7] = 4; D[8] = 5;
	D[9] = 7; D[10] = 9;
	for (int i = 11; i <= N; i++) {
		D[i] = D[i - 1] + D[i - 5];
	}
	return 0;
}
int main()
{
	int N,temp;
	Dynamic(100);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		printf("%lld\n", D[temp]);
	}
	return 0;
}