#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int N;
bool solution(string A) {
	int check_count = 0;
	for (int i = 0; i < A.length(); i++) {
		if (A[i] == '(') check_count++;
		else check_count--;
		if (check_count < 0) return false;
	}
	if (check_count != 0) return false;
	return true;
}
int main() {
	string A;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> A;
		if (solution(A)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}