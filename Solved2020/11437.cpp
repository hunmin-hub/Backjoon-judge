#include <stdio.h>
#include <unordered_map>
#include <queue>
#include <math.h>
#define MAX 50002
#define MAXI(A,B) A>B ? A : B
using namespace std;
unordered_map<int, vector<int> > tree;
int N;
int parent[22][MAX],depth[MAX];
int max_depth;
bool visit[MAX];
int LCA(int a, int b) {
	if (depth[a] < depth[b]) {
		for (int i = max_depth; i >= 0; i--) {
			if (depth[a] <= depth[parent[i][b]]) {
				b = parent[i][b];
			}
		}
	}
	if (a == b) return a;

	for (int i = max_depth; i >= 0; i--) {
		if (parent[i][a] != parent[i][b]) {
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}
void BFS(int vertex) { // 1번노드, 루트로 설정
	queue<pair<int,int> > v_queue;
	parent[0][1] = 1;
	v_queue.push(make_pair(vertex,1));
	while (!v_queue.empty()) {
		int current = v_queue.front().first;
		int level = v_queue.front().second;
		visit[current] = true;
		depth[current] = level;
		max_depth = MAXI(level, max_depth);
		v_queue.pop();
		for (int i = 0; i < tree[current].size(); i++) {
			int next = tree[current][i];
			if (!visit[next]) {
				parent[0][next] = current; // 각 정점의 부모노드 삽입
				v_queue.push(make_pair(next,level+1));
			}
		}
	}
	max_depth = (int)floor(log2(max_depth));
}
void find_parent() {
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= N; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
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