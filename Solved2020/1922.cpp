#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int answer = 0;
int parents[1002];
vector<vector<int> > edge;
int find_parents(int x) {
	if (parents[x] == x) return x;
	return parents[x] = find_parents(parents[x]);
}
void union_set(int x, int y) {
	x = find_parents(x);
	y = find_parents(y);
	parents[y] = x;
}
int solution() {
	int x, y, cost;
	for (int i = 0; i < edge.size(); i++) {
		x = edge[i][0];
		y = edge[i][1];
		cost = edge[i][2];
		if (find_parents(x) != find_parents(y)) {
			union_set(x, y);
			answer += cost;
		}
	}
	return answer;
}
bool comp(vector<int>& A, vector<int>& B) {
	return A[2] < B[2];
}
int main() {
	int a, b, c;
	cin >> N;
	for (int i = 1; i <= N; i++) parents[i] = i;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edge.push_back({ a,b,c });
	}
	sort(edge.begin(), edge.end(), comp);
	cout << solution();
	return 0;
}