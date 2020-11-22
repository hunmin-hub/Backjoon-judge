// 비트연산문제
#include<stdio.h>
#define MAX 16
void process(int n,int arr1[],int arr2[])
{
	for (int i = 0; i < n; i++) {
		arr1[i] = arr1[i] | arr2[i];
	}
	for (int i = 0; i < n;i++) {
		for (int j = n-1; j>=0; j--) { // 높은자리부터 비교(왼쪽)
			if (arr1[i] & (1 << j)) {
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

}
int main()
{
	int n = 6; // map의 크기
	int result[MAX];
	int test1[MAX] = { 46,33,33,22,31,50 };
	int test2[MAX] = { 27,56,19,14,14,10 };
	process(n, test1, test2);
	return 0;
}