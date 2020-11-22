#include<stdio.h>
#define MAX 10001
int selfnumber(int N)
{
	if (N >= 10) {
		return (N % 10) + selfnumber(N / 10);
	}
	else {
		return N;
	}
}
int main()
{
	int result = 0;
	bool check[MAX];
	for (int i = 1; i <= 10000; i++) {
		result += selfnumber(i);
		result += i;
		if (result <= 10000) {
			check[result] = 1;
		}
		result = 0;
	}
	for (int i = 1; i <= 10000; i++) {
		if (check[i]!=1) {
			printf("%d\n", i);
		}
	}
	return 0;
}