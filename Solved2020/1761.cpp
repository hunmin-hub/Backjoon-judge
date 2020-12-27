#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <math.h>
#define MAXI(A,B) A>B ? A : B
using namespace std;
unordered_map<int, vector<pair<int,int> > > tree;
queue<pair<int, int> > v_queue;
int N,maxi_depth;
int root_dis[40002], parent[25][40002],depth[40002];
bool visit[40002];
void BFS(int vertex) { // root는 1번노드로 설정
	parent[0][1] = 1;
	v_queue.push(make_pair(vertex, 1));
	while (!v_queue.empty()) {
		int current = v_queue.front().first;
		int level = v_queue.front().second;
		maxi_depth = MAXI(maxi_depth, level);
		depth[current] = level;
		visit[current] = true;
		v_queue.pop();
		for (int i = 0; i < tree[current].size(); i++) {
			int next = tree[current][i].first;
			int next_dis = tree[current][i].second;
			if (!visit[next]) {
				parent[0][next] = current;
				root_dis[next] = root_dis[current] + next_dis;
				v_queue.push(make_pair(next, level+1));
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
	int m,a, b, c;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}
	BFS(1);
	find_parent();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (depth[a] > depth[b]) {
			swap(a, b);
		}
		printf("%d\n", root_dis[a]+root_dis[b]-2*root_dis[LCA(a, b)]);
	}
	return 0;
}