#include <iostream>
#include <vector>
#define INF 200000001
using namespace std;
vector<pair<int, int> > bound, new_bound;
vector<int> calc;
int last_city;
int re(int value) {
    if (value > last_city) return last_city;
    if (value <= 0) return 1;
    return value;
}
int solution(int n, vector<int> stations, int w)
{
    last_city = n;
    bool flag = true;
    int answer = 0;
    int range = 2 * w + 1;
    int N = stations.size();
    for (int i = 0; i < N; i++) {
        bound.push_back(make_pair(re(stations[i] - w), re(stations[i] + w)));
    }
    bound.push_back(make_pair(INF, INF));
    pair<int, int> temp;
    for (int i = 0; i < N; i++) {
        if (flag) {
            temp.first = bound[i].first;
            temp.second = bound[i].second;
            flag = false;
        }
        if (temp.second + 1 >= bound[i + 1].first) {
            temp.second = bound[i + 1].second;
            continue;
        }
        if (temp.second + 1 < bound[i + 1].first) {
            new_bound.push_back(temp);
            flag = true;
        }
    }
    if (new_bound[0].first != 1) {
        calc.push_back(new_bound[0].first - 1);
    }
    for (int i = 0; i < new_bound.size() - 1; i++) {
        calc.push_back(((new_bound[i + 1].first) - (new_bound[i].second) - 1));
    }
    if (new_bound[new_bound.size() - 1].second != n) {
        calc.push_back(n - new_bound[new_bound.size() - 1].second);
    }
    for (int i = 0; i < calc.size(); i++) {
        if (calc[i] % range != 0) {
            answer += (calc[i] / range) + 1;
        }
        else {
            answer += (calc[i] / range);
        }
    }
    return answer;
}