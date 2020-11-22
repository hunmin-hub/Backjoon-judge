#include<stdio.h>
#define MAX 1001
int n;
int num[MAX];
int f_dp[MAX], r_dp[MAX];
int front_dynamic()
{
	f_dp[0] = 1;
	for (int i = 1; i < n; i++) {
		f_dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (num[i] > num[j] && f_dp[i] < f_dp[j] + 1) {
				f_dp[i] = f_dp[j] + 1;
			}
		}
	}
	return 0;
}
int rear_dynamic()
{
	r_dp[n-1] = 1;
	for (int i = n-2; i >=0; i--) {
		r_dp[i] = 1;
		for (int j = i+1; j <n; j++) {
			if (num[i] > num[j] && r_dp[i] < r_dp[j] + 1) {
				r_dp[i] = r_dp[j] + 1;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	int maxi = 1;
	front_dynamic();
	rear_dynamic();
	for (int i = 0; i < n; i++) {
		if (maxi < f_dp[i] + r_dp[i] - 1) {
			maxi = f_dp[i] + r_dp[i] - 1;
		}
	}
	printf("%d", maxi);
	return 0;
}