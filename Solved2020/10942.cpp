#include<stdio.h>
int Dy[2002][2002]; // Dy[i][j] = i~j 팰린드롬 ? 1 : 0
int N, board[2002];
void solution() {
	// 1
	for (int i = 0; i <N; i++) {
		Dy[i][i] = 1;
	}
	// 2
	for (int i = 0; i <N - 1; i++) {
		if (board[i] == board[i + 1]) {
			Dy[i][i + 1] = 1;
		}
	}
	// 3 이상
	for (int k = 3; k <= N; k++) {
		for (int i = 0; i <= N - k; i++) {
			int j = i + k - 1; // i~j가 팰린드롬이기 위해서 양끝이 같고 i+1,j-1이 팰린드롬이면 팰린드롬이다
			if (board[i] == board[j] && Dy[i + 1][j - 1] == 1) {
				Dy[i][j] = 1;
			}
		}
	}
}
int main() {
	int T, a, b;
	scanf("%d", &N);
	for (int i = 0; i <N; i++) {
		scanf("%d", &board[i]);
	}
	solution();
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", Dy[a-1][b-1]);
	}
}