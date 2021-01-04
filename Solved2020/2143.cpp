#include <stdio.h>
#include <unordered_map>
using namespace std;
int T, N, M;
int A[1002], B[1002];
int Dy_A[1002],Dy_B[1002];
long long answer = 0;
unordered_map<int, long long> A_map;
unordered_map<int, long long> B_map;
unordered_map<int, long long>::iterator it;
long long solution() {
	// A
	for (int i = 1; i <= N; i++) {
		Dy_A[i] = Dy_A[i - 1] + A[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			A_map[Dy_A[j] - Dy_A[i - 1]]++;
		}
	}
	// B
	for (int i = 1; i <= M; i++) {
		Dy_B[i] = Dy_B[i - 1] + B[i];
	}
	for (int i = 1; i <= M; i++) {
		for (int j = i; j <= M; j++) {
			B_map[Dy_B[j] - Dy_B[i - 1]]++;
		}
	}
	long long a_c, b_c;
	for (it = A_map.begin(); it != A_map.end(); it++) {
		a_c = it->second;
		b_c = B_map[T - (it->first)];
		answer += a_c * b_c;
	}
	return answer;
}
int main() {
	scanf("%d", &T);
	scanf("%d", &N);
	for (int i = 1; i <=N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d", &B[i]);
	}
	printf("%lld",solution());
	return 0;
}