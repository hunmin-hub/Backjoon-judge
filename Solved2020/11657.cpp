#include <stdio.h>
#include <algorithm>
#define INF 9999999999
int n, m;
long long edge[6002][3],root_dis[502];
using namespace std;
void solution() {
	root_dis[1] = 0; // 1번 루트 설정
	int from, to, cost;
	for (int i = 1; i <=n - 1; i++) {
		for (int j = 0; j < m; j++) {
			from = edge[j][0],to = edge[j][1],cost = edge[j][2];
			if (root_dis[from] == INF) continue;
			if (root_dis[to] > root_dis[from] + cost) {
				root_dis[to] = root_dis[from] + cost;
			}
		}
	}
}
bool check_cycle() {
	int from, to, cost;
	for (int i = 0; i < m; i++) {
		from = edge[i][0],to = edge[i][1],cost = edge[i][2];
		if (root_dis[from] == INF) continue;
		if (root_dis[to] > root_dis[from] + cost) {
			return false; // 음의 사이클 존재
		}
	}
	return true;
}
void print() {
	if (!check_cycle()) {
		printf("-1");
		return;
	}
	for (int i = 2; i <= n; i++) {
		if (root_dis[i] == INF) printf("-1\n");
		else printf("%lld\n", root_dis[i]);
	}
}
int main() {
	int a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[i][0] = a;
		edge[i][1] = b;
		edge[i][2] = c; // cost
	}
	for (int i = 1; i <= n; i++) root_dis[i] = INF;
	solution();
	print();
	return 0;
}