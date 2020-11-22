#include<stdio.h>
#include<math.h>
int n, k;
int buy[501];
long double mini = 999999999999;
int BT(int K)
{
	long double sum = 0, m, A = 0;
	for (int i = 0; i <= n - K; i++) {
		A = 0;
		sum = 0;
		for (int j = i; j < i + K; j++) {
			sum += buy[j];
		}
		m = sum / (double)K; // m Æò±Õ
		for (int j = i; j < i + K; j++) {
			A += ((buy[j] - m) * (buy[j] - m));
		}
		A = A / (double)K; // A ºÐ»ê
		if (mini > sqrt(A)) {
			mini = sqrt(A);
		}
	}
	return 0;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &buy[i]);
	}
	for (int i = k; i <= n; i++) {
		BT(i);
	}
	printf("%.11Lf", mini);
	return 0;
}