#include<stdio.h>
#include<math.h>
#define MAX 1300000
int N = 1299709;
int era[MAX];
int request[MAX];
int Dy[MAX];
int answer;
int eratos()
{
	for (int i = 2; i <= sqrt(N); i++) {
		if (era[i] == 1) continue;
		for (int j = i * 2; j <= N; j += i) {
			era[j] = 1;
		}
	}
	return 0;
}
int dynamic()
{
	for (int i = 2; i <= N; i++) {
		if (era[i] == 1) {
			Dy[i] = Dy[i - 1] + 1;
		}
	}
	return 0;
}
int main()
{
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &request[i]);
	}
	eratos();
	dynamic();

	for (int i = 0; i < a; i++) {
		if (era[request[i]] == 0) {
			printf("0\n");
			continue;
		}
		//answer = Dy[request[i]];
		for (int j=1;;j++) {
			if (Dy[request[i] + j] == 0) {
				answer = Dy[request[i] + j - 1];
				break;
			}
		}
		printf("%d\n", answer+1);
	}
	return 0;
}