#include<stdio.h>
#define MAX 102
int graph[MAX][MAX];
int visit[MAX];
int M, N;
int a, b;
int DFS(int V)
{
	for (int i = 1; i <= N; i++) {
		if (graph[V][i] == 1 && visit[i] == 0) {
			visit[i] = 1;
			DFS(i);
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	visit[1] = 1;
	DFS(1);
	
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1) {
			count++;
		}
	}
	printf("%d", count-1);
	return 0;
}