#include<stdio.h>
#define MAX 1000001
int N;
long long num[MAX], num_list[MAX];
int path[MAX];
long long result[MAX];
int lower_bound(int start, int end, long long v)
{
	int mid;
	for (;;) {
		mid = (start + end) / 2;
		if (num_list[mid] < v) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
		if (start >= end) {
			end = start;
			break;
		}
	}
	return end;
}
int lis()
{
	int temp, maxi = 0;
	num_list[0] = num[0];
	for (int i = 1; i < N; i++) {
		temp = lower_bound(0, maxi + 1, num[i]);
		num_list[temp] = num[i];
		if (maxi < temp) maxi = temp;

		path[i] = temp;
	}
	return maxi+1;
}
int main()
{
	int length;
	int count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &num[i]);
	}
	length=lis();
	printf("%d\n", length);
	for (int i = N - 1; i >= 0;i--) {
		if (path[i] == length-1) {
			result[count++] = num[i];
			length--;
		}
	}
	for (int i = count - 1; i >= 0; i--) {
		printf("%lld ", result[i]);
	}
	return 0;
}