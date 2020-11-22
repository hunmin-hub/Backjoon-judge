#include<stdio.h>
#define MAX 11
int train[MAX][2];
int main()
{
	int result;
	int maxi = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d %d", &train[i][0], &train[i][1]);
	}
	result = train[0][1];
	maxi = result;
	for (int i = 1; i < 10; i++) {
		result = result - train[i][0] + train[i][1];
		if (maxi < result) maxi = result;
	}
	printf("%d", maxi);
	return 0;
}