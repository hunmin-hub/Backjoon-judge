#include<stdio.h>
#include<math.h>
#include<memory.h>
#define MAX 7500000
int sosu[500002];
bool check[MAX+2];
void sosu_check()
{
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (check[i] == 0) {
			for (int j = i * i; j <= MAX; j += i) {
				check[j] = 1;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int count = 0;
	sosu_check();
	for (int i = 2; i <= MAX; i++) {
		if (count == 500001) break;
		if (check[i] == 0) {
			sosu[count++] = i;
		}
	}
	printf("%d", sosu[n - 1]);
	return 0;
}