#include<stdio.h>
#include<math.h>
#define MAX 101
int num[MAX];
int N, M;
int temp = 300001;
int BT(int flag,int count,int sum,int point)
{
	if (flag == 1) {
		sum += num[point];
		count++;
	}
	if (sum > M) return 0;
	if (count == 3) {
		if (temp > M - sum) {
			temp = M - sum;
		}
		return 0;
	}
	if (point == N - 1) return 0;
	BT(1, count, sum, point + 1);
	BT(0, count, sum, point + 1);
	return 0;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	BT(1, 0, 0, 0);
	BT(0, 0, 0, 0);
	printf("%d", M-temp);
	return 0;
}