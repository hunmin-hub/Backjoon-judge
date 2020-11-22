#include<stdio.h>
#include<string.h>
#define MAX 20
char num[MAX];
int number[MAX];
int n;
int sorting()
{
	int temp;
	int maxi = -1;
	int maxi_f = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (maxi < number[j]) {
				maxi = number[j];
				maxi_f = j;
			}
		}
		temp = number[i];
		number[i] = maxi;
		number[maxi_f] = temp;
		maxi = -1;
	}
	return 0;
}
int main()
{
	scanf("%s", num);
	
	n=strlen(num);
	for (int i = 0; i < n; i++) {
		number[i] = num[i] - '0';
	}

	sorting();

	for (int i = 0; i < n; i++) {
		printf("%d", number[i]);
	}
	return 0;
}