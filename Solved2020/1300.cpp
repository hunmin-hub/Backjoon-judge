#include <stdio.h>
#define MINI(A,B) A>B ? B : A
int N,K;
long long row_count(int target) { // N*N�迭���� �� �� ���� target���� ������ : f(target)
	long long count = 0;
	for (int i = 1; i <= N; i++) {
		count += MINI(target / i, N);
	}
	return count;
}
int solution() {
	// f(MID) =K�� ������Ű�� �ּҰ��� ã�ƶ�. -> �̺�Ž��
	int start = 1, end = K,mid,answer;
	long long temp;
	while (start <= end) {
		mid = (start + end) / 2;
		temp = row_count(mid);
		if (temp >= K) {
			answer = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return answer;
}
int main() {
	scanf("%d", &N);
	scanf("%d", &K);
	printf("%d",solution());
	return 0;
}