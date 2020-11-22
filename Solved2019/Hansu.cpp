#include<stdio.h>
int check(int n)
{
	int check_num[10];
	int count = 0,temp=0;
	for (;;) {
		check_num[count++] = n % 10;
		if (n < 10) {
			break;
		}
		n /= 10;
	}
	if (count >2) {
		temp = check_num[0] - check_num[1];
		for (int i = 1; i < count-1; i++) {
			if (temp == check_num[i] - check_num[i + 1]) {
				temp = check_num[i] - check_num[i + 1];
			}
			else {
				return 0;
				break;
			}
		}
	}
	return 1;
}
int main()
{
	int N,ans=0;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		if (check(i) == 1) {
			ans++;
		}
	}
	
	printf("%d", ans);
	return 0;
}