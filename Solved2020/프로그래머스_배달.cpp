#include <iostream>
#include <vector>
using namespace std;
#define INF 99999999
int dist[52];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<int> > edge;
    for (int i = 0; i < road.size(); i++) {
        int from = road[i][0];
        int to = road[i][1];
        int cost = road[i][2];
        edge.push_back({ from,to,cost });
        edge.push_back({ to,from,cost });
    }
    for (int i = 1; i <= N; i++) dist[i] = INF;
    dist[1] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int from = edge[j][0];
            int to = edge[j][1];
            int cost = edge[j][2];
            if (dist[from] == INF) continue;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }
    return answer;
}