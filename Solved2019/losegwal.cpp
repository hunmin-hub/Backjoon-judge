#include<stdio.h>
#include<string.h>
#define MAX 52
char calc[MAX];
int stack_num[MAX];
int stack_oper[MAX];
int visit[MAX];
int main()
{
	int num_count = 0;
	int oper_count = 0;
	int temp_count = 0;
	int num_temp[MAX];
	scanf("%s", calc);
	
	bool flag = 0;
	int number = 0;
	int ten = 1;
	for (int i = 0; i <= strlen(calc); i++) {
		if (calc[i] >= '0' && calc[i] <= '9') {
			flag = 1;
			num_temp[temp_count++] = calc[i]-'0';
		}
		else {
			flag = 0;
			for (int j = temp_count - 1; j >= 0; j--) {
				number += num_temp[j] * ten;
				ten *= 10;
			}
			stack_num[num_count++] = number;
			stack_oper[oper_count++] = calc[i];
			number = 0;
			ten = 1;
			temp_count = 0;
		}
	}
	flag = 1;
	int start_flag, end_flag;
	int sum = 0;
	for (int i = 0; i <= oper_count;i++) {
		if (stack_oper[i] == '+' && flag==1) {
			start_flag = i;
			flag = 0;
		}
		else if(stack_oper[i]!='+' && flag==0) {
			end_flag = i;
			for (int j = start_flag; j <= end_flag; j++) {
				visit[j] = 1;
				sum += stack_num[j];
			}
			visit[start_flag] = 0;
			stack_num[start_flag] = sum;
			sum = 0;
			flag = 1;
		}
	}
	int result = stack_num[0];
	for (int i = 1; i <num_count; i++) {
		if (visit[i] == 0) {
			result -= stack_num[i];
		}
	}
	printf("%d", result);
	return 0;
}