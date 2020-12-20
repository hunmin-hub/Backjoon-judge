#include <string>
#include <vector>

using namespace std;
int graph[202][202];
int visit[202];
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int current_v;
    int level = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i + 1][j + 1] = computers[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<int> vertex;
        if (visit[i] == 0) {
            vertex.push_back(i);
            level++;
        }
        while (!vertex.empty()) {
            current_v = vertex.front();
            visit[current_v] = level;
            vertex.erase(vertex.begin());
            for (int j = 1; j <= n; j++) {
                if (current_v == j) continue;
                if (graph[current_v][j] == 1 && visit[j] == 0) {
                    vertex.push_back(j);
                }
            }
        }
    }
    answer = level;
    return answer;
}