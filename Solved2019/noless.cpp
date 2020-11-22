#include<stdio.h>
#define MAX 65
long long dy[MAX][10];
long long ans[MAX];
int dynamic()
{
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		dy[1][i] = 1;
	}
	for (int i = 2; i <= 64; i++) {
		sum = 0;
		for (int j = 0; j <= 9; j++) {
			sum += dy[i - 1][j];
			dy[i][j] = sum;
		}
	}
	sum = 0;
	for (int i = 1; i <= 64; i++) {
		sum = 0;
		for (int j = 0; j <= 9; j++) {
			sum += dy[i][j];
		}
		ans[i] = sum;
	}
	return 0;
}
int main()
{
	dynamic();
	int n,m;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		printf("%lld\n", ans[m]);
	}
	
	return 0;
}