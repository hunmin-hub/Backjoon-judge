#include<stdio.h>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
unordered_map<int, vector<int> > tree_sun; // 부모노드를 담는 맵
unordered_map<int, vector<int> > tree_mother; // 자식노드들을 담는맵

unordered_map<int, bool> tree_visit; // 노드들 방문여부

void solution(int case_num,vector<pair<int, int> > edge) {
	queue<int> vertex;
	unordered_map<int, vector<int> >::iterator it;
	unordered_map<int, bool>::iterator ct;
	int root = 0; // 루트의 개수
	int root_node; // 루트노드
	for (int i = 0; i < edge.size(); i++) {
		tree_sun[edge[i].second].push_back(edge[i].first);
		tree_mother[edge[i].first].push_back(edge[i].second);
		tree_visit[edge[i].first] = true;
		tree_visit[edge[i].second] = true;
	}
	for (it = tree_sun.begin(); it != tree_sun.end(); it++) { // 부모노드 검사
		if (it->second.size() > 1) {
			printf("Case %d is not a tree.\n", case_num);
			return;
		}
	}
	for (it = tree_mother.begin(); it != tree_mother.end(); it++) { // 루트 검사
		if (tree_sun[it->first].size() == 0) {
			root_node = it->first;
			root++;
		}
		if (root > 1) {
			printf("Case %d is not a tree.\n", case_num);
			return;
		}
	}
	if (root == 0 && edge.size()>0) {
		printf("Case %d is not a tree.\n", case_num);
		return;
	}
	vertex.push(root_node); // 경로가 유일한지 조사 (bfs)
	while (!vertex.empty()) {
		int current = vertex.front();
		tree_visit[current] = false;
		vertex.pop();
		for (int i = 0; i < tree_mother[current].size(); i++) {
			if (tree_visit[tree_mother[current][i]]) {
				vertex.push(tree_mother[current][i]);
			}
		}
	}
	for (ct = tree_visit.begin(); ct != tree_visit.end(); ct++) {
		if (ct->second == true) {
			printf("Case %d is not a tree.\n", case_num);
			return;
		}
	}
	printf("Case %d is a tree.\n", case_num);
	return;
}
int main() {
	int a, b,case_num=0;
	vector<pair<int,int>> edge;
	while (true) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) {
			case_num++;
			solution(case_num,edge);
			edge.clear();
			tree_sun.clear();
			tree_mother.clear();
			tree_visit.clear();
			continue;
			// 초기화
		}
		if (a <0 && b <0) break;
		edge.push_back(make_pair(a, b));
	}
	return 0;
}