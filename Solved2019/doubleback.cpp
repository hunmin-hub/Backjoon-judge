#include<stdio.h>
#define MAX 10002
int number[MAX];
int N;
int gugan[2][2];
int reverse(int x, int y)
{
	int temp[MAX];
	int count = 0;
	for (int i = y; i >= x; i--) {
		temp[count++] = number[i];
	}
	count = 0;
	for (int i = x; i <= y; i++) {
		number[i] = temp[count++];
	}
	return 0;
}
int front_reverse()
{
	int r_count = 0;
	for (int i = 0; i < N; i++) {
		if (number[i] != i + 1) {
			for (int j = i + 1; j < N; j++) {
				if (number[j] == i + 1) {
					gugan[r_count][0] = i + 1;
					gugan[r_count][1] = j + 1;
					reverse(i, j);
					r_count++;
				}
				if (r_count == 2) return 0;
			}
		}
	}
	return 0;
}
int rear_reverse()
{
	int r_count = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (number[i] != i + 1) {
			for (int j = 0; j < i;j++) {
				if (number[j] == i + 1) {
					gugan[r_count][0] = j + 1;
					gugan[r_count][1] = i + 1;
					reverse(j, i);
					r_count++;
				}
				if (r_count == 2) return 0;
			}
		}
	}
	return 0;
}
int main()
{
	int temper[MAX];

	gugan[0][0] = 1; gugan[0][1] = 1;
	gugan[1][0] = 1; gugan[1][1] = 1;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);
		temper[i] = number[i];
	}

	front_reverse();
	int flag = 0;
	for (int i = 0; i < N; i++) {
		if (number[i] != i + 1) {
			flag = 1;
			break;
		}
	}
	if (flag ==0) {
		for (int i = 0; i < 2; i++) {
			printf("%d %d\n", gugan[i][0], gugan[i][1]);
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			number[i] = temper[i];
		}

		rear_reverse();
		flag = 0;
		for (int i = 0; i < N; i++) {
			if (number[i] != i + 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			for (int i = 0; i < 2; i++) {
				printf("%d %d\n", gugan[i][0], gugan[i][1]);
			}
		}
	}
	return 0;
}
