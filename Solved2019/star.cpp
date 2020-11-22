#include<stdio.h>
#define MAX 6561
char star[MAX][MAX];
int fill(int x, int y, int z)
{
	if (z == 1) {
		star[x][y] = '*';
	}
	else {
		// 9분할
		fill(x, y, z / 3);
		fill(x, y + z / 3, z / 3);
		fill(x, y + z / 3 * 2, z / 3);

		fill(x + z / 3, y, z / 3);
		//fill(x + z / 3, y + z / 3, z / 3); 구멍부분입니다
		fill(x + z / 3, y + z / 3 * 2, z / 3);

		fill(x + z / 3 * 2, y, z / 3);
		fill(x + z / 3 * 2, y+z/3, z / 3);
		fill(x + z / 3 * 2, y+z/3*2, z / 3);
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star[i][j] = ' ';
		}
	}
	fill(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", star[i][j]);
		}
		printf("\n");
	}
	return 0;
}