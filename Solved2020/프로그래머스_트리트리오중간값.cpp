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
    find_path(1, 0); // 1:������ �������� ���� �� ���� A�� ã�´�.
    for (int i = 0; i < 2; i++) {
        // 1���� ã�� ���� A���� �ٽ� �� �� ������ ���� �� ���� B���� ã�´�.
        next_v = tree_length[max_step][0];
        max_step = -1;
        tree_length.clear();
        find_path(next_v, 0);
        if (tree_length[max_step].size() > 1) return max_step; // ���� �� ����(Ʈ���� ����)�� 2���̻��̸� �߰��� Ȯ��
        // 1����� �ѹ� �� ����B�� ���ؼ� ���� �� ���� C���� ã�ƺ���.
    }
    return max_step - 1; // 2�� �õ����� ������ 1���� ������ Ʈ���� ������ 1��
}