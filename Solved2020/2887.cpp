#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int N,answer=0;
int parents[100002];
vector<vector<int> > x_cost, y_cost, z_cost;
vector<vector<int> > edge;
void make_edge(vector<vector<int> > costs) {
	int from, to, cost;
	for (int i = 1; i < costs.size(); i++) {
		from = costs[i][0];
		to = costs[i-1][0];
		cost = abs(costs[i][1] - costs[i - 1][1]);
		edge.push_back({ from,to,cost });
	}
}
bool comp(vector<int>& A, vector<int>& B) {
	return A[1] < B[1];
}
bool compare(vector<int>& A, vector<int>& B) {
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
	make_edge(x_cost);
	make_edge(y_cost);
	make_edge(z_cost);
	sort(edge.begin(), edge.end(), compare);
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
	int x, y, z;
	cin >> N;
	for (int i = 1; i <=N; i++) {
		parents[i] = i;
		cin >> x >> y >> z;
		x_cost.push_back({ i,x });
		y_cost.push_back({ i,y });
		z_cost.push_back({ i,z });
	}
	sort(x_cost.begin(), x_cost.end(), comp);
	sort(y_cost.begin(), y_cost.end(), comp);
	sort(z_cost.begin(), z_cost.end(), comp);
	cout << solution();
	return 0;
}