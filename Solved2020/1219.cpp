#include <stdio.h>
int N,M,start,end;
int edge[200][3],city[105];
long long dist[105];
int INF = -99999999;
bool cycle_city[105];
void solution() {
	for (int i = 0; i < N; i++) dist[i] = INF;
	dist[start] = city[start];
	for (int i = 1; i <=N+100; i++) {
		for (int j = 0; j < M; j++) {
			int from = edge[j][0];
			int to = edge[j][1];
			int cost = edge[j][2];
			if (dist[from] == INF) continue;
			if (dist[to] < dist[from] + cost + city[to]) {
				if (i >= N && dist[end] != INF) {
					cycle_city[to] = true;
					cycle_city[from] = true;
					dist[to] = INF * (-1);
					dist[from] = INF * (-1);
				}
				dist[to] = dist[from] + cost + city[to];
			}
		}
	}
	if (dist[end] == INF) {
		printf("gg");
		return;
	}
	if (cycle_city[end]) {
		printf("Gee");
		return;
	}
	printf("%lld", dist[end]);
	
}
int main() {
	int a, b, c;
	scanf("%d %d %d %d", &N,&start,&end,&M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[i][0] = a;
		edge[i][1] = b;
		edge[i][2] = c * (-1);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &city[i]);
	}
	solution();
}