#include<stdio.h>
int GCD(int A, int B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}
int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	int gcd_num=GCD(A, B);
	printf("%d\n", gcd_num);
	A /= gcd_num;
	B /= gcd_num;
	int LCD = A * B * gcd_num;
	printf("%d", LCD);
	return 0;
}