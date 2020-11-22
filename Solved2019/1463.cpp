#include<stdio.h>
#define MINI(a, b) (((a)<(b))?(a):(b))
#define MAX 1000002
int dy[MAX];
int N;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		if (i + 1 <= 1000000) {
			if (dy[i + 1] == 0)	dy[i + 1] = dy[i] + 1;
			else dy[i + 1] = MINI(dy[i + 1], dy[i] + 1);
		}

		if (i * 2 <= 1000000) {
			if (dy[i * 2] == 0) dy[i * 2] = dy[i] + 1;
			else dy[i * 2] = MINI(dy[i * 2], dy[i] + 1);
		}	
		
		if (i * 3 <= 1000000) {
			if (dy[i * 3] == 0) dy[i * 3] = dy[i] + 1;
			else dy[i * 3] = MINI(dy[i * 3], dy[i] + 1);
		}
	}
	printf("%d", dy[N]);
	return 0;
}