// Kruskal MST 최소비용신장트리
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, int> parent;
bool compare(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}
int find_parent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
}
void union_set(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    parent[y] = x; // 루트와 루트의 연결
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int x, y;
    for (int i = 0; i < n; i++) parent[i] = i;
    sort(costs.begin(), costs.end(), compare);
    for (int i = 0; i < costs.size(); i++) {
        x = costs[i][0], y = costs[i][1];
        if (find_parent(x) != find_parent(y)) { // 추가할 간선이 사이클이 아니라면
            union_set(x, y); // 두 트리를 연결
            answer += costs[i][2];
        }
    }
    return answer;
}