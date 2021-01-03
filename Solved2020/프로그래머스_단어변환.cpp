#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
#define INF 99999999
unordered_map<string, int> dist;
vector<pair<string, string> > edge;
bool edge_check(string A, string B) {
    int count = 0;
    for (int i = 0; i < A.length(); i++) {
        if (A[i] != B[i]) count++;
    }
    if (count <= 1) return true;
    return false;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    for (int i = 0; i < words.size(); i++) {
        dist[words[i]] = INF;
        if (edge_check(begin, words[i])) {
            edge.push_back(make_pair(begin, words[i]));
            edge.push_back(make_pair(words[i], begin));
        }
        for (int j = i + 1; j < words.size(); j++) {
            if (edge_check(words[i], words[j])) {
                edge.push_back(make_pair(words[i], words[j]));
                edge.push_back(make_pair(words[j], words[i]));
            }
        }
    }
    dist[target] = INF;
    dist[begin] = 0;
    for (int i = 0; i < dist.size() - 1; i++) {
        for (int j = 0; j < edge.size(); j++) {
            string from = edge[j].first;
            string to = edge[j].second;
            int cost = 1;
            if (dist[from] == INF) continue;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
            }
        }
    }
    answer = dist[target];
    if (answer == INF) return 0;
    return answer;
}