#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, vector<int>> graph;
unordered_map<int, int> dis_map;
bool visit[20002];
vector<pair<int, int>> node_queue; // pair: vertex,distance
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int node = 0, distance = 0;
    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    visit[1] = true;
    for (int i = 0; i < graph[1].size(); i++) {
        node = graph[1][i];
        visit[node] = true;
        node_queue.push_back(pair(node, 1));
    }
    while (!node_queue.empty()) {
        // vector front_pop으로 자료구조 queue 구현
        node = node_queue.front().first;
        distance = node_queue.front().second;
        node_queue.erase(node_queue.begin());

        dis_map[distance]++;

        for (int i = 0; i < graph[node].size(); i++) {
            if (!visit[graph[node][i]]) {
                visit[graph[node][i]] = true;
                node_queue.push_back(pair(graph[node][i], distance + 1));
            }
        }
    }
    answer = dis_map[distance];
    return answer;
}