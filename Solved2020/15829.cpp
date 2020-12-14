#include<stdio.h>
#include<string.h>
#define MAX 52
char key[MAX];
int n;
long long solution() {
	long long answer = 0;
	long long sosu = 1;
	long long MOD = 1234567891;
	for (int i = 0; i < strlen(key); i++) {
		answer = (answer + (key[i] - 'a' + 1) * sosu) % MOD;

		sosu = ((sosu * 31)) % MOD;
	}
	return answer;
}
int main() {
	scanf("%d", &n);
	scanf("%s", key);

	printf("%lld",solution());
	return 0;
}