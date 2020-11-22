#include<stdio.h>
#include<string.h>
#define MAX 1002
#define maxi(a,b) ( (a) >= (b) ) ? (a):(b) 
char sample1[MAX], sample2[MAX];
int dy[MAX][MAX];
int n, m;
int main()
{
	scanf("%s", sample1);
	n = strlen(sample1);

	scanf("%s", sample2);
	m = strlen(sample2);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dy[i][j] = 0;
		}
	}
	
	for (int i = 0; i < m; i++) {
		if (sample1[0] == sample2[i]) {
			for (int j = i; j < m; j++) {
				dy[j][0] = 1;
			}
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (sample2[0] == sample1[i]) {
			for (int j = i; j < n; j++) {
				dy[0][j] = 1;
			}
			break;
		}
	}
	
	int temp;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			temp = maxi(dy[i - 1][j], dy[i][j - 1]);
			if (sample2[i] == sample1[j]) dy[i][j] = maxi(temp, dy[i - 1][j - 1] + 1);
			else dy[i][j] = maxi(temp, dy[i - 1][j - 1]);
		}
	}

	printf("%d", dy[m-1][n-1]);
	return 0;
}