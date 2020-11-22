#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 100001
int rof[MAX];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &rof[i]);
	}
	sort(rof, rof + N);
	int temp;
	int maxi = 0;
	for (int i = 0; i < N; i++) {
		temp = rof[i] * (N - i);
		if (maxi< temp) maxi = temp;
	}

	printf("%d", maxi);
	return 0;
}