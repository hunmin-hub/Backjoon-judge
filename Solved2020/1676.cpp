#include<stdio.h>
int five_check(int num)
{
	int count = 0;
	for (;;) {
		if (num % 5 == 0) {
			count++;
			num /= 5;
		}
		else {
			break;
		}
	}
	return count;
}
int main()
{
	int N,answer=0;
	scanf("%d", &N);
	for (int i = N; i >= 1; i--) {
		answer+=five_check(i);
	}
	printf("%d", answer);
	return 0;
}