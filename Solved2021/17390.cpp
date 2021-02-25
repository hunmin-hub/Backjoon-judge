#include<iostream>
#include<algorithm>
using namespace std;
int Dy[300003];
int main() {
	int N, Q;
	int L, R;
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &Dy[i]);
	}
	sort(Dy+1, Dy + N+1);
	for (int i = 1; i <= N; i++) {
		Dy[i]+=Dy[i - 1];
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &L, &R);
		printf("%d\n", Dy[R] - Dy[L - 1]);
	}
	return 0;
}