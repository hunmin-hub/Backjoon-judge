// ��Ʈ���깮��
#include<stdio.h>
#define MAX 16
void process(int n,int arr1[],int arr2[])
{
	for (int i = 0; i < n; i++) {
		arr1[i] = arr1[i] | arr2[i];
	}
	for (int i = 0; i < n;i++) {
		for (int j = n-1; j>=0; j--) { // �����ڸ����� ��(����)
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
	int n = 6; // map�� ũ��
	int result[MAX];
	int test1[MAX] = { 46,33,33,22,31,50 };
	int test2[MAX] = { 27,56,19,14,14,10 };
	process(n, test1, test2);
	return 0;
}