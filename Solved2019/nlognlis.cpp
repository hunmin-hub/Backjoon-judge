#include<stdio.h>
#define MAX 1000001
int N;
int num[MAX];
int num_list[MAX];
int lower_bound(int start, int end, int key)
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
	int temp=0,maxi=0;
	num_list[0] = num[0];
	for (int i = 1; i < N; i++) {
		temp = lower_bound(0, maxi+1, num[i]);
		if (maxi < temp) maxi = temp;
		num_list[temp] = num[i];

	}
	return maxi;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	printf("%d", lis()+1);
	return 0;
}