#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int parents[10002];
int answer = 0;
vector<vector<int> > edge;
bool comp(vector<int>& A, vector<int>& B) {
	return A[2] < B[2];
}
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
int main() {
	int a, b,c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parents[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back({ a,b,c });
	}
	sort(edge.begin(), edge.end(), comp);
	cout<<solution();
	return 0;
}