#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 1001
int time[MAX];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &time[i]);
	}
	sort(time,time+N);

	int result = 0;
	for (int i = 0; i < N; i++) {
		for(int j=0;j<=i;j++) {
			result += time[j];
		}
	}
	printf("%d", result);
	return 0;
}