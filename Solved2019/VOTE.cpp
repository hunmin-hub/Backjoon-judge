#include<stdio.h>
#define MAX 1002
int vote[3][3];
int N;
int main()
{
	int a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a);
			vote[0][j] += a;
			if (a == 3) vote[1][j]++;
			else if (a == 2) vote[2][j]++;
		}
	}
	int maxi = vote[0][0];
	int maxi_i = 0;
	bool flag = 0;
	for (int i = 1; i < 3; i++) {
		if (maxi < vote[0][i]) {
			maxi = vote[0][i];
			maxi_i = i;
			if (flag == 1) flag = 0;
		}
		else if (maxi == vote[0][i]) {
			if (vote[1][maxi_i] < vote[1][i]) {
				maxi = vote[0][i];
				maxi_i = i;
				if (flag == 1) flag = 0;
			}
			else if (vote[1][maxi_i] == vote[1][i] && vote[2][maxi_i] < vote[2][i]) {
				maxi = vote[0][i];
				maxi_i = i;
				if (flag == 1) flag = 0;
			}
			else if (vote[1][maxi_i] == vote[1][i] && vote[2][maxi_i] == vote[2][i]) {
				flag = 1;
			}
		}
	}
	if (flag == 1) printf("0 %d", maxi);
	else printf("%d %d", maxi_i+1, maxi);
	return 0;
}