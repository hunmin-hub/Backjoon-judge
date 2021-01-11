#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
unordered_map<int, vector<int> > trees;
unordered_map<int, vector<int> > tree_length;
bool visit[250002];
int max_step = -1;
void find_path(int vertex, int step) {
    visit[vertex] = true;
    if (max_step <= step) {
        max_step = step;
        tree_length[max_step].push_back(vertex);
    }
    for (int i = 0; i < trees[vertex].size(); i++) {
        if (!visit[trees[vertex][i]]) {
            find_path(trees[vertex][i], step + 1);
        }
    }
    visit[vertex] = false;
}
int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    int x, y, next_v;
    for (int i = 0; i < edges.size(); i++) {
        x = edges[i][0];
        y = edges[i][1];
        trees[x].push_back(y);
        trees[y].push_back(x);
    }
    find_path(1, 0); // 1:임의의 한점에서 가장 먼 정점 A을 찾는다.
    for (int i = 0; i < 2; i++) {
        // 1에서 찾은 정점 A에서 다시 또 그 점에서 가장 먼 정점 B들을 찾는다.
        next_v = tree_length[max_step][0];
        max_step = -1;
        tree_length.clear();
        find_path(next_v, 0);
        if (tree_length[max_step].size() > 1) return max_step; // 가장 먼 정점(트리의 지름)이 2개이상이면 중간값 확정
        // 1개라면 한번 더 정점B에 대해서 가장 먼 정점 C들을 찾아본다.
    }
    return max_step - 1; // 2번 시도에도 정점이 1개만 나오면 트리의 지름은 1개
}