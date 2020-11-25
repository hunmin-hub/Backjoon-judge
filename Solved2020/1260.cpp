#include<stdio.h>
#include<queue>
using namespace std;
#define MAX 1005
queue<int> q;
int N, M,start;
int graph[MAX][MAX], v_DFS[MAX], v_BFS[MAX];
int DFS(int v)
{
	printf("%d ", v);
	v_DFS[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1 && v_DFS[i] == 0) {
			DFS(i);
		}
	}
	return 0;
}
int BFS(int v)
{
	printf("%d ", v);
	v_BFS[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[v][i] == 1 && v_BFS[i] == 0) {
			q.push(i);
		}
	}
	return 0;
}
int main()
{
	int a,b;
	scanf("%d %d %d", &N, &M,&start);
	for (int i = 0; i < M; i++) {
		scanf("%d %d",&a,&b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	DFS(start);
	printf("\n");
	q.push(start);
	while (!q.empty()) {
		if (v_BFS[q.front()] == 0) BFS(q.front());
		q.pop();
	}
	return 0;
}