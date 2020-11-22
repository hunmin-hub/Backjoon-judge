#include<stdio.h>
#define MAX 100000
int N;
int syom(int num)
{
	int np[MAX],count = 0, flag = 0,ck=0;
	for (;;) {
		np[count++]=num % 10;
		if (num % 10 == 6)	ck++;
		else ck = 0;
		if (ck == 3) return 1;
		if (num < 10) break;
		num /= 10;
	}
	return 0;
}
int main()
{
	int number = 1;
	int check = 0;
	scanf("%d", &N);
	for (;;) {
		if (syom(number) == 1)	check++;
		if (check == N) {
			printf("%d", number);
			break;
		}
		number++;
	}
	return 0;
}