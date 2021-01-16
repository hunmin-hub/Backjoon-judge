#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int, int> trees;
unordered_map<int, int> parents;
int N;
int tree_node;
int from, to;
vector<vector<int> > edge;
void make_tree() {
	int left_node, right_node;
	tree_node = N+1;
	while (!edge.empty()) {
		for (int i = 0; i < edge.size(); i++) {
			left_node = edge[i][0];
			right_node = edge[i][1];
			if (edge[i][2] == 2) {
				trees[left_node] = tree_node;
				trees[right_node] = tree_node;
				if (i - 1 >= 0) {
					edge[i - 1][1] = tree_node;
					edge[i - 1][2]--;
				}
				if (i + 1 < edge.size()) {
					edge[i + 1][0] = tree_node;
					edge[i + 1][2]--;
				}
				edge.erase(edge.begin() + i);
				tree_node++;
			}
		}
	}
}
int find_parents(int x, int y) {
	int depth = 1;
	while (x != 0) {
		x = trees[x];
		parents[x] = depth++;
	}
	depth = 1;
	while (y != 0) {
		y = trees[y];
		depth++;
		if (parents[y] != 0) {
			break;
		}
	}
	return (parents[y] + depth-1);
}
int main() {
	int a;
	cin >> N;
	for (int i = 1; i <=N-1; i++) {
		cin >> a;
		edge.push_back({ i,i + 1,a });
	}
	cin >> from >> to;
	make_tree();
	printf("%d", find_parents(from, to));
	return 0;
}