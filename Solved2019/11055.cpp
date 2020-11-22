#include<stdio.h>
#define MAX 1001
int n;
int num[MAX], dp[MAX];
int dynamic()
{
	int maxi = num[0];
	dp[0] = num[0];
	for (int i = 1; i < n; i++) {
		dp[i] = num[i];
		for (int j = i - 1; j >= 0; j--) {
			if (num[i] > num[j] && dp[i] < dp[j] + num[i]) {
				dp[i] = dp[j] + num[i];
			}
		}
		if (maxi < dp[i]) maxi = dp[i];
	}
	return maxi;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	printf("%d", dynamic());
	return 0;
}