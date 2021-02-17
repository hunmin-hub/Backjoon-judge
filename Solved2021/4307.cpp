#include<iostream>
using namespace std;
#define MAXI(A,B) (A>B) ? (A) : (B)
#define MINI(A,B) (A>B) ? (B) : (A)
int main() {
	int T;
	int N, L, X;
	int max_t,min_t;
	cin >> T;
	while (T-- > 0) {
		cin >> L >> N;
		max_t = 0, min_t = 0;
		for (int i = 0; i < N; i++) {
			cin >> X;
			max_t = MAXI(max_t, (MINI(X, L - X)));
			min_t = MAXI(min_t, (MAXI(X, L - X)));
		}
		cout << max_t << " "<<min_t << "\n";
	}
	return 0;
}