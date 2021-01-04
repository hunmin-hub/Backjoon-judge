#include <stdio.h>
#include <vector>
using namespace std;
int board[10005], temp[10005];
int N;
void combine(int left, int right) {
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
	if (left >= right) return;
	int mid = (left + right) / 2;
	divide(left, mid);
	divide(mid + 1, right);
	combine(left, right);
}
int solution() {
	int answer = 0;
	vector<int> positive,negative,zero;
	for (int i = 0; i < N; i++) {
		if (board[i] < 0) negative.push_back(board[i]);
		else if (board[i] == 0) zero.push_back(board[i]);
		else positive.push_back(board[i]);
	}
	int i=0;
	while (i < negative.size()) {
		if (i + 1 < negative.size()) {
			answer += (negative[i] * negative[i + 1]);
			i += 2;
		}
		else {
			if (!zero.empty()) {
				zero.pop_back();
			}
			else {
				answer += negative[i];
			}
			i++;
		}
	}
	i = positive.size()-1;
	while (i>=0) {
		if (i - 1 >=0) {
			if (positive[i] == 1 || positive[i - 1] == 1) {
				answer += positive[i];
				i--;
			}
			else {
				answer += (positive[i] * positive[i - 1]);
				i -= 2;
			}
		}
		else {
			answer += positive[i];
			i--;
		}
	}
	return answer;
}
int main() {
	int answer = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &board[i]);
	}
	divide(0, N - 1);
	printf("%d",solution());
}