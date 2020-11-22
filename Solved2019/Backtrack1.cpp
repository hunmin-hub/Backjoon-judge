#include<stdio.h>
#define MAX 10
int N, M;
int num[MAX];
void BT(int n,int m)
{
	int flag = 0;
	num[m] = n;
	if (m + 1 == M) {
		for (int i = 0; i <=m; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		flag = 0;
		for (int j = 0; j <=m; j++) {
			if (num[j] == i) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			BT(i, m + 1);
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		BT(i, 0);
	}
	return 0;
}