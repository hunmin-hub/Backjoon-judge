#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
unordered_map<int, vector<int>> graph;
unordered_map<int, int> tree;
queue<int> v_queue;
bool visit[100002];
int main() {
	int m,x,y;
	int vertex;
	scanf("%d", &m);
	for (int i = 0; i < m - 1; i++) {
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	v_queue.push(1);
	while (!v_queue.empty()) {
		vertex=v_queue.front();
		visit[vertex] = true;
		v_queue.pop();
		for (int i = 0; i < graph[vertex].size(); i++) {
			if (!visit[graph[vertex][i]]) {
				tree[graph[vertex][i]] = vertex;
				v_queue.push(graph[vertex][i]);
			}
		}
	}
	for (int i = 2; i <= m; i++) {
		printf("%d\n", tree[i]);
	}
}