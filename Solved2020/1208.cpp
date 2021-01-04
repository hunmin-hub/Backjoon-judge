#include<stdio.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
unordered_map<long long, long long> A_map;
unordered_map<long long, long long> B_map;
int N, target;
int A[25], B[25];
int A_size=1, B_size=1;
void DFS(int board[],int vertex,long long sum,int size,int what_map,int step) {
	if (vertex == size-1) {
		//printf("%lld\n", sum);
		if (what_map == 0 && step!=0) A_map[sum]++;
		else if(what_map==1 && step!=0) B_map[sum]++;
		return;
	}
	DFS(board, vertex + 1, sum + board[vertex + 1],size,what_map,step+1);
	DFS(board, vertex + 1, sum,size,what_map,step);
	return;
}
long long solution() {
	long long answer = 0;
	DFS(A, 0, 0, A_size,0,0);
	DFS(B, 0, 0, B_size, 1,0);
	for (auto it = A_map.begin(); it != A_map.end(); it++) {
		long long temp = target - (it->first);
		answer += (it->second) * B_map[temp];
	}
	answer += A_map[target];
	answer += B_map[target];
	return answer;
}
int main() {
	scanf("%d %d", &N, &target);
	for (int i = 1; i <=N / 2; i++) {
		scanf("%d", &A[i]);
		A_size++;
	}
	B_size = 1;
	for (int i = N / 2 + 1; i <= N; i++) {
		scanf("%d", &B[B_size++]);
	}
	printf("%lld",solution());
}