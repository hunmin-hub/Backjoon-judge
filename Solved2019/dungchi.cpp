#include<stdio.h>
#define MAX 51
int main()
{
	int n, phy[MAX][2],rank[MAX];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &phy[i][0], &phy[i][1]); // 0 : ¸ö¹«°Ô 1: Å°
		rank[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (phy[i][0] > phy[j][0] && phy[i][1] > phy[j][1]) {
					rank[j]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", rank[i]);
	}
	return 0;
}