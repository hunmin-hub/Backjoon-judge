#include<stdio.h>
#define MAX 105
int graph[MAX][MAX];
int path[MAX][MAX];
int N;
int DFS(int start,int v)
{
	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1 && path[start][i]==0) {
			//printf("%d %d\n", start, i);
			path[start][i] = 1;
			DFS(start,i);
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		DFS(i, i);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}
	return 0;
}