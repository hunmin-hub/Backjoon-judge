#include<stdio.h>
#define MAX 1001
int n;
int num[MAX], dp[MAX], dis[MAX];
int maxi = 1;
int final_dis = -1;
int dynamic()
{
	dp[0] = 1;
	dis[0] = -1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		dis[i] = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (num[i] > num[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				dis[i] = j;
			}
		}
		if (maxi < dp[i]) {
			maxi = dp[i];
			final_dis = i;
		}
	}
	return maxi;
}
int find_dis()
{
	int result[MAX];
	int count = 0,temp;
	for (;;) {
		if (final_dis == -1) break;
		result[count++] = num[final_dis];
		temp = final_dis;
		final_dis = dis[temp];
	}
	for (int i = count - 1; i >= 0; i--) {
		printf("%d ", result[i]);
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	printf("%d\n",dynamic());
	if (final_dis == -1) printf("%d", num[0]);
	else find_dis();
	return 0;
}