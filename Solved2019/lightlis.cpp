#include<stdio.h>
#define MAX 100001
int N;
int num[MAX][2];
int check[500002];
int num_list[MAX];
int visit[MAX];
int result[MAX];
int lis_lower_bound(int start, int end, int key)
{
	int mid;
	for (;;) {
		mid = (start + end) / 2;
		if (num_list[mid] < key) start = mid + 1;
		else end = mid;

		if (start >= end) break;
	}
	return end;
}
int lis()
{
	int temp, maxi = 0;
	num_list[0] = num[0][1];
	for (int i = 1; i < N; i++) {
		temp = lis_lower_bound(0, maxi+1, num[i][1]);
		num_list[temp] = num[i][1];
		visit[i] = temp;
		if (maxi < temp) maxi = temp;
	}
	return maxi;
}
int main()
{
	int length;
	int count = 0;
	int a, b;
	scanf("%d", &N);
	for (int i = 1; i <= 500000; i++) check[i] = -1;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		check[a] = b;
	}
	for (int i = 1; i <= 500000; i++) {
		if (check[i] != -1) {
			num[count][0] = i;
			num[count][1] = check[i];
			count++;
		}
	}
	count = 0;

	length = lis() + 1;

	for (int i = N-1; i >= 0; i--) {
		if (visit[i] == length - 1) {
			length--;
		}
		else {
			result[count++] = num[i][0];
		}
	}
	printf("%d\n", count);
	for (int i = count - 1; i >= 0; i--) {
		printf("%d\n", result[i]);
	}
	return 0;
}