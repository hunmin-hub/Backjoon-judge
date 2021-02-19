#include<iostream>
using namespace std;
int N, L;
int is_going(int current_time,int stop,int go) {
	int check = current_time % (stop + go);
	if (check <= stop) return current_time + (stop - check);
	return current_time;
}
int main() {
	int x, a, b;
	int current_time = 0,prev=0;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> x >> a >> b;
		current_time += (x - prev);
		current_time = is_going(current_time, a, b);
		prev = x;
	}
	current_time += (L - x);
	cout << current_time;
	return 0;
}