#include<stdio.h>
int A, B, C;
int X, Y;
int main()
{
	int money = 0;
	scanf("%d %d %d", &A, &B, &C);
	scanf("%d %d", &X, &Y);
	if (A + B > C*2) {
		if (A > C * 2) {
			A = C * 2;
		}
		if (B > C * 2) {
			B = C * 2;
		}
		if (X >= Y) {
			money += Y * 2 * C;
			money += (X - Y) * A;
		}
		else if (X < Y) {
			money += X * 2 * C;
			money += (Y - X) * B;
		}
	}
	else {
		money += (X * A) + (Y * B);
	}
	printf("%d", money);
	return 0;
}