#include<stdio.h>
#include<string.h>
#define MAX 1002
#define maxi(a,b) ( (a) >= (b) ) ? (a):(b) 
char sample1[MAX], sample2[MAX];
int dy[MAX][MAX];
int n, m;
int path[MAX][MAX];
char result[MAX];
int count = 0;
int go_path(int x, int y)
{
	if (path[x][y] == 2) { // 대각
		result[count++] = sample1[y];
		go_path(x - 1, y - 1);
	}
	else if (path[x][y] == 1) { // 왼쪽
		go_path(x, y - 1);
	}
	else if (path[x][y] == -1) { // 종결
		result[count++] = sample1[y];
		return 0;
	}
	else if (path[x][y] == 3) { // 위
		go_path(x - 1, y);
	}
	return 0;
}
void PRINT()
{
	for(int i=count-1;i>=0;i--) {
		printf("%c", result[i]);
	}
}
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
				path[j][0] = 3;
			}
			path[i][0] = -1;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (sample2[0] == sample1[i]) {
			for (int j = i; j < n; j++) {
				dy[0][j] = 1;
				path[0][j] = 1;
			}
			path[0][i] = -1;
			break;
		}
	}

	int temp;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			temp = maxi(dy[i - 1][j], dy[i][j - 1]);
			if (sample2[i] == sample1[j]) {
				if (temp <= dy[i - 1][j - 1] + 1) {
					dy[i][j] = dy[i - 1][j - 1] + 1;
					path[i][j] = 2;
				}
				else {
					dy[i][j] = temp;
					path[i][j] = 1;
				}
			}
			else {
				if (dy[i - 1][j] > dy[i][j - 1]) path[i][j] = 3;
				else path[i][j] = 1;
				dy[i][j] = temp;
			}
		}
	}
	go_path(m - 1, n - 1);
	printf("%d\n", dy[m - 1][n - 1]);
	PRINT();
	return 0;
}