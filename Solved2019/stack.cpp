#include<stdio.h>
#define MAX 100002
int num[MAX];
int top;
int main()
{
	int N, a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		if (a != 0) {
			num[top++] = a;
		}
		else if (a == 0) {
			top--;
		}
	}
	int result = 0;
	for (int i = 0; i < top; i++) {
		result += num[i];
	}
	printf("%d", result);
	return 0;
}