#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
#define INF 99999999
bool sosu[10000];
int sosu_key[10000],dist[10000];
int sosu_count = 0;
vector<pair<int,int> > edge;
void era() {
	for (int i = 2; i <= sqrt(9999); i++) {
		if (sosu[i]) continue;
		for (int j = i * 2; j <= 9999; j += i) {
			sosu[j] = true;
		}
	}
	sosu_count = 0;
	for (int i = 1000; i <= 9999; i++) {
		if (!sosu[i]) {
			sosu_key[sosu_count++] = i;
		}
	}
}
bool check(int a, int b) {
	string A = to_string(a);
	string B = to_string(b);
	int check_count = 0;
	for (int i = 0; i < 4; i++) {
		if (A[i] == B[i]) check_count++;
	}
	if (check_count == 3) return true;
	return false;
}
void make_edge() {
	for (int i = 0; i < sosu_count; i++) {
		for (int j = i + 1; j < sosu_count; j++) {
			if (check(sosu_key[i], sosu_key[j])) {
				edge.push_back(make_pair(sosu_key[i], sosu_key[j]));
				edge.push_back(make_pair(sosu_key[j], sosu_key[i]));
			}
		}
	}
}
int solution(int start, int end) {
	int N = sosu_count;
	for (int i = 1000; i <= 9999; i++) dist[i] = INF;
	dist[start] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int from = edge[j].first;
			int to = edge[j].second;

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + 1) {
				dist[to] = dist[from] + 1;
			}
		}
	}
	return dist[end];
}
int main() {
	int T,a,b;
	era();
	make_edge();
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n",solution(a, b));
	}
	return 0;
}