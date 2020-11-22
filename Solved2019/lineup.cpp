#include<stdio.h>
#include<algorithm>
#include<vector>
#define MAX 32002
using namespace std;
int N, M;
int degree[MAX];
int sorting[MAX];
vector<vector<int>> ver;
int main()
{
	int a, b;
	int cnt = 0;
	scanf("%d %d", &N, &M);
	ver.resize(N + 1);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		degree[b]++;
		ver[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			sorting[cnt++] = i;
		}
	}
	int temp;
	int out_node;
	for (;;) {
		if (cnt == 0) break;
		temp = sorting[cnt - 1];
		cnt--;
		printf("%d ", temp);
		for (;;) {
			if (ver[temp].size() == 0) break;
			out_node = ver[temp].back();
			degree[out_node]--;
			ver[temp].pop_back();
			if (degree[out_node] == 0) {
				sorting[cnt++] = out_node;
			}
		}
	}
	return 0;
}