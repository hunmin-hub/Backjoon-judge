#include<stdio.h>
#include<string.h>
#define MAX 102
int dy[MAX][MAX][MAX];
char sample1[MAX], sample2[MAX], sample3[MAX];
int n, m, l;
int maxi(int a, int b, int c)
{
	if (a >= b&& a >= c) return a;
	if (b >= a&& b >= c) return b;
	if (c >= a && c >= b) return c;
}
int main()
{
	scanf("%s", sample1);
	n = strlen(sample1);
	scanf("%s", sample2);
	m = strlen(sample2);
	scanf("%s", sample3);
	l = strlen(sample3);

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= l; k++) {
				if (sample1[i-1] == sample2[j-1] && sample2[j-1] == sample3[k-1]) {
					dy[i][j][k] = dy[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dy[i][j][k]=maxi(dy[i - 1][j][k],dy[i][j - 1][k],dy[i][j][k - 1]);
				}
			}
		}
	}
	printf("%d", dy[n][m][l]);
	return 0;
}