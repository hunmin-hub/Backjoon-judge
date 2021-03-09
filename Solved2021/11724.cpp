#include<iostream>
using namespace std;
int N, M;
int graph[1002][1002];
bool visit[1002];
void DFS(int vertex) {
	visit[vertex] = true;
	for (int i = 1; i <= N; i++) {
		if (!visit[i] && graph[vertex][i] == 1) {
			DFS(i);
		}
	}
}
int main() {
	int a, b,answer=0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			answer++;
			DFS(i);
		}
	}
	cout << answer;
	return 0;
}