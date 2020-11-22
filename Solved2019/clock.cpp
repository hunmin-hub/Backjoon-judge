#include<stdio.h>
int main()
{
	int hour, minute;
	scanf("%d %d", &hour, &minute);
	if (minute - 45 < 0) {
		hour--;
		minute = minute + 15;
	}
	else if (minute - 45 >= 0) {
		minute -= 45;
	}
	if (hour == -1) {
		hour = 23;
	}
	printf("%d %d", hour, minute);
	return 0;
}