#include<stdio.h>
#include<math.h>
#define MAX 12
int graph[MAX][MAX];
int ingu[MAX];
int group_num[MAX];
int N,M;
int first = 0, second = 0;
int f_group[MAX], s_group[MAX];
int ingu1, ingu2;
int result;
int mini = 9999999;
int visit[MAX];
int ingu_cal()
{
	ingu1 = 0, ingu2 = 0;
	for (int i = 0; i < first; i++) {
		ingu1 += ingu[f_group[i]];
	}
	for (int i = 0; i < second; i++) {
		ingu2 += ingu[s_group[i]];
	}
	return abs(ingu1 - ingu2);
}
//------------------------------------------------------------------------------//
int DFS(int V,int groups[])
{
	if (group_num[V] != group_num[groups[0]]) return 0;
	for (int i = 1; i <= N; i++) {
		if (graph[V][i] == 1 && visit[i]==0) {
			visit[i] = 1;
			DFS(i,groups);
		}
	}
	return 0;
}
int group_checking(int to,int groups[])
{
	if (to == 1) return 0;
	for (int i = 0; i <= N; i++) visit[i] = 0;

	visit[groups[0]] = 1;
	DFS(groups[0],groups);

	for (int i = 0; i < to; i++) {
		if (visit[groups[i]] == 0) return 1;
	}
	return 0;
}
//-------------------------------------------------------------------------------//
int grouping(int k)
{
	if (k == N + 1) {
		first = 0;
		second = 0;
		for (int i = 1; i <= N; i++) {
			if (group_num[i] == 1) {
				f_group[first++] = i;
			}
			else if (group_num[i] == 2) {
				s_group[second++] = i;
			}
		}
		
		if (first == N || second == N) return 0;
		if (group_checking(first, f_group) == 1) return 0;
		if (group_checking(second, s_group) == 1) return 0;

		result=ingu_cal();
		if (mini > result) {
			mini = result;
		}
		return 0;
	}
	group_num[k] = 1; // 1번 그룹
	grouping(k + 1);
	group_num[k] = 2; // 2번 그룹
	grouping(k + 1);
	return 0;
}
int main()
{
	int temp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &ingu[i + 1]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &M);
		for (int j = 0; j < M; j++) {
			scanf("%d", &temp);
			graph[i + 1][temp] = 1;
			graph[temp][i + 1] = 1;
		}
	}
	grouping(1);

	if (mini == 9999999) printf("-1");
	else printf("%d", mini);
	return 0;
}