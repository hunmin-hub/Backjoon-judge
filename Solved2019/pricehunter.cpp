#include <stdio.h>
int calc1_price(int rank)
{
	int price = 0;
	if (rank == 1) price = 5000000;
	else if (rank >= 2 && rank <= 3) price = 3000000;
	else if (rank >= 4 && rank <= 6) price = 2000000;
	else if (rank >= 7 && rank <= 10) price = 500000;
	else if (rank >= 11 && rank <= 15) price = 300000;
	else if (rank >= 16 && rank <= 21) price = 100000;
	return price;
}
int calc2_price(int rank)
{
	int price = 0;
	if (rank == 1) price = 5120000;
	else if (rank >= 2 && rank <= 3) price = 2560000;
	else if (rank >= 4 && rank <= 7) price = 1280000;
	else if (rank >= 8 && rank <= 15) price = 640000;
	else if (rank >= 16 && rank <= 31) price = 320000;
	return price;
}
int main()
{
	int n,a,b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n",calc1_price(a) + calc2_price(b));
	}
	return 0;
}