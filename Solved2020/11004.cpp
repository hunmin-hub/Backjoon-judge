#include <stdio.h>
int N, K;
int board[5000002];
int temp[5000002];
void combine(int left,int right) {
	int mid = (left + right) / 2;
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (board[i] <= board[j]) {
			temp[k++] = board[i++];
		}
		else {
			temp[k++] = board[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = board[i++];
	}
	while (j <= right) {
		temp[k++] = board[j++];
	}
	for (int i = left; i <= right; i++) {
		board[i] = temp[i];
	}

}
void divide(int left, int right) {
	if (right <= left) return;
	int mid = (left + right)/2;
	divide(left, mid);
	divide(mid + 1, right);
	combine(left, right);
}
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i <N; i++) {
		scanf("%d", &board[i]);
	}
	divide(0, N-1);
	printf("%d", board[K - 1]);
	return 0;
}