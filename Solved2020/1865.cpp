#include <stdio.h>
#include <algorithm>
#define INF 99999999
using namespace std;
void solution(int edge[][3],int n,int m,int w) {
	long long v_dis[502];
	for (int i = 1; i <= n; i++) v_dis[i] = INF;
	v_dis[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2*m + w; j++) {
			int from = edge[j][0];
			int to = edge[j][1];
			int cost = edge[j][2];
			if (v_dis[to] > v_dis[from] + cost) {
				v_dis[to] = v_dis[from] + cost;
				if (i == n) {
					printf("YES\n"); // 음의사이클 존재
					return;
				}
			}
		}
	}
	printf("NO\n");
}
void process() {
	int edge[5500][3];
	int a, b, c;
	int n, m, w;
	scanf("%d %d %d", &n, &m, &w);
	for (int i = 0; i < m*2; i+=2) {
		scanf("%d %d %d", &a, &b, &c);
		edge[i][0] = a, edge[i][1] = b, edge[i][2] = c;
		edge[i + 1][0] = b, edge[i + 1][1] = a, edge[i + 1][2] = c;
	}
	for (int i = 0; i < w; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[2*m + i][0] = a;
		edge[2*m + i][1] = b;
		edge[2*m + i][2] = (c * (-1));
	}
	solution(edge,n,m,w);
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		process();
	}
	return 0;
}