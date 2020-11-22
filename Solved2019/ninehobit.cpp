#include<stdio.h>
#include<algorithm>
using namespace std;
int high[10];
int visit[10];
int BT(int n,int sum,int count)
{
	if (sum == 100 && count == 7) {
		sort(visit, visit + 7);
		for (int i = 0; i < count; i++) {
			printf("%d\n", visit[i]);
		}
		exit(0);
	}
	if (n == 9) return 0;
	sum += high[n];
	visit[count] = high[n];
	BT(n + 1, sum,count+1);
	sum -= high[n];
	BT(n + 1, sum,count);
	return 0;
}
int main()
{
	for (int i = 0; i < 9; i++) {
		scanf("%d", &high[i]);
	}
	BT(0, 0, 0);
	return 0;
}