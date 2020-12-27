#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <queue>
#include <math.h>
#define MAXI(A,B) A>B ? A : B
using namespace std;
unordered_map<int, vector<int> > tree;
queue<int> v_queue;
int N,depth[100002];
int parent[30][100002];
int maxi_depth;
bool visit[100002];
void BFS(int vertex) {
	v_queue.push(vertex);
	depth[vertex] = 1;
	while (!v_queue.empty()) {
		int current = v_queue.front();
		v_queue.pop();
		visit[current] = true;
		maxi_depth = MAXI(maxi_depth, depth[current]);
		for (int i = 0; i < tree[current].size(); i++) {
			int next = tree[current][i];
			if (!visit[next]) {
				parent[0][next] = current;
				depth[next] = depth[current] + 1;
				v_queue.push(next);
			}
		}
	}
	maxi_depth = (int)floor(log2(maxi_depth));
}
void find_parent() {
	for (int i = 1; i <= maxi_depth; i++) {
		for (int j = 1; j <= N; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
}
int LCA(int a, int b) {
	for (int i = maxi_depth; i >= 0; i--) {
		if (depth[a] <= depth[parent[i][b]]) {
			b = parent[i][b];
		}
	}
	if (a == b) return a;
	for (int i = maxi_depth; i >= 0; i--) {
		if (parent[i][a] != parent[i][b]) {
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}
int main() {
	int a, b, m;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	BFS(1);
	find_parent();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (depth[a] > depth[b]) {
			swap(a, b);
		}
		printf("%d\n", LCA(a, b));
	}
	return 0;
}