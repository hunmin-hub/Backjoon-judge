#include<stdio.h>
#define MAX 50
int N;
int c_high[MAX]; // 세로
int c_left[MAX]; // 왼대각
int c_right[MAX]; // 우대각
int result = 0;
int fill(int x, int y)
{
	c_high[y]++;
	c_left[x+y]++;
	c_right[x - y + 15]++;
	return 0;
}
int erase(int x, int y)
{
	c_high[y]--;
	c_left[x+y]--;
	c_right[x - y + 15]--;
	return 0;
}
int check(int x, int y)
{
	if (c_high[y] == 0 && c_left[x+y] == 0 && c_right[x - y + 15] == 0) {
		return 1;
	}
	return 0;
}
int back(int x,int y,int count)
{
	if (count == N) {
		result++;
		return 0;
	}
	else {
		if (check(x,y)==1) {
			fill(x, y);
			for (int i = 1; i <= N; i++) {
				if (check(x+1,i)==1) {
					back(x+1, i, count + 1);
				}
			}
			erase(x, y);
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		back(1, i, 1);
	}
	printf("%d", result);
	return 0;
}