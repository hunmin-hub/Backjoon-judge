#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2147483647
#define MINI(A,B) A>B ? B : A
using namespace std;
vector<pair<int, int> > meat;
bool compare(pair<int, int>& A, pair<int, int>& B) {
	if (A.first == B.first) {
		return A.second > B.second;
	}
	return A.first < B.first;
}
int main() {
	int N, M;
	int weight, cost;
	int current_weight=0, current_cost=0;
	int min_cost = INF;
	bool flag = false;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> weight >> cost;
		meat.push_back(make_pair(cost, weight));
	}
	sort(meat.begin(), meat.end(),compare);
	for (int i = 0; i <N; i++) {
		current_weight += meat[i].second;
		if (i - 1 >= 0) {
			if (meat[i].first == meat[i - 1].first) current_cost += meat[i - 1].first;
			else current_cost = 0; // 다음 가격으로 사면 지금까지는 다 공짜로 얻을 수 있으므로
		}
		if (current_weight >= M) {
			flag = true;
			min_cost = MINI(min_cost, meat[i].first + current_cost);
		}
	}
	if (!flag) cout << -1;
	else cout << min_cost;
	return 0;
}