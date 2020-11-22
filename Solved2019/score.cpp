#include<stdio.h>
int main()
{
	int n;
	int num[102];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	int flag = 1,score=0;
	for (int i = 0; i < n; i++) {
		if (num[i] == 1) {
			score += flag;
			flag++;
		}
		else {
			flag = 1;
		}
	}
	printf("%d", score);
	return 0;
}