#include<stdio.h>
#include<algorithm>
using namespace std;
int num[11];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &num[j]);
		}
		sort(num, num + 10);
		printf("%d\n", num[7]);
	}
	return 0;
}