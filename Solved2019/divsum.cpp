#include<stdio.h>
int num;
int divsum(int N)
{
	int sum = N;
	for (;;) {
		sum += N % 10;
		if (N < 10) break;
		N /= 10;
	}
	if (num == sum) return 1;
	return 0;
}
int main()
{
	scanf("%d", &num);
	for (int i = 0; i <= num; i++) {
		if (divsum(i) == 1) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}