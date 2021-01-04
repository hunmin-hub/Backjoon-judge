#include <stdio.h>
#include <algorithm>
using namespace std;
int N;
int A[4002], B[4002], C[4002], D[4002];
int CD_map[16000002];
long long answer = 0;
long long solution() {
	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			CD_map[count++]=C[i]+D[j];
		}
	}
	sort(CD_map, CD_map + count);
	int target;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			target = (A[i] + B[j]) * (-1);
			auto lower_number=lower_bound(CD_map, CD_map + count, target); // target 이상의 값 첫번째 
			if (*lower_number != target) continue;
			auto upper_number = upper_bound(CD_map, CD_map + count, target); // target 초과의 값 첫번째
			answer += (upper_number - lower_number); // 중복 개수

		}
	}
	return answer;
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <=N; i++) {
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}
	printf("%lld", solution());
	return 0;
}