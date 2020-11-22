#include<stdio.h>
#define MAX 1000001
int N;
long long num[MAX];
long long num_list[MAX];
int lower_bound(int start, int end, long long key)
{
	int mid;
	for (;;) {
		mid = (start + end) / 2;
		if (num_list[mid] < key) start = mid + 1;
		else end = mid;

		if (start >= end) {
			end = start;
			break;
		}
	}
	return end;
}
int lis()
{
	int temp, maxi=0;
	num_list[0] = num[0];
	for (int i = 1; i < N; i++) {
		temp = lower_bound(0, maxi+1, num[i]);
		num_list[temp] = num[i];
		if (maxi < temp) maxi = temp;
	}
	for (int i = 0; i <= maxi; i++) {
		printf("%d->", num_list[i]);
	}
	printf("\n");
	return maxi;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &num[i]);
	}
	printf("%d", lis() + 1);
	return 0;
}