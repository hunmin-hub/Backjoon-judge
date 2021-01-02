#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(vector<int>& A, vector<int>& B) {
    if (A[0] == B[0]) return A[1] > B[1];
    return A[0] < B[0];
}
int solution(vector<vector<int>> routes) {
    vector<pair<int, int> > cars; // first : start / second : end
    int answer = 0;
    bool flag = false;
    int s, e, cs, ce;
    sort(routes.begin(), routes.end(), compare);
    for (int i = 0; i < routes.size(); i++) {
        s = routes[i][0], e = routes[i][1];
        flag = false;
        for (int j = 0; j < cars.size(); j++) {
            cs = cars[j].first, ce = cars[j].second;
            if (!(cs <= s && s <= ce)) {
                flag = true;
                break;
            }
        }
        if (flag) {
            answer++;
            cars.clear();
        }
        cars.push_back(make_pair(s, e));
    }
    if (!cars.empty()) answer++;
    return answer;
}