#include<stdio.h>
int main()
{
	char strnum[100];
	int n,sum=0;
	scanf("%d", &n);
	scanf("%s", strnum);
	for (int i = 0; i < n; i++) {
		sum += strnum[i] - 48;
	}
	printf("%d", sum);
	return 0;
}