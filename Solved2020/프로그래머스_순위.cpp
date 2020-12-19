#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int graph[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int check = 0;
    for (int i = 0; i < results.size(); i++) {
        graph[results[i][0]][results[i][1]] = 1; // 탐색용 그래프 graph
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) { // 각 정점에 대해 검사
        check = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 1 || graph[j][i] == 1) {
                check++;
            }
        }
        if (check == n - 1) { // 부모노드+자식노드 == n-1
            answer++;
        }
    }
    return answer;
}