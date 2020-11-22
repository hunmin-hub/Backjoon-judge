#include<stdio.h>
#include<string.h>
char exam[32];
int stack[100];
int n;
int mystack()
{
	int count = 0;
	int temp = 0;
	int result = 1;
	int flag = 0;

	int cir_check=0, rec_check=0;
	for (int i = 0; i < n; i++) {
		if (exam[i] == '(')  cir_check++;
		else if (exam[i] == '[') rec_check++;
		else if (exam[i] == ')') cir_check--;
		else if (exam[i] == ']') rec_check--;
	}
	if (cir_check != 0 || rec_check != 0) return -1;
	for (int i = 0; i <n; i++) {
		if (exam[i] == '(' || exam[i]=='[') {
			stack[count++] =exam[i];
		}
		else if (exam[i] == ')') {
			
			temp = 0;
			count--;
			flag = 0;
			for(;;) {
				if (stack[count] == '(') {
					if (flag == 0) temp = 1;
					stack[count++]=temp * 2;
					break;
				}
				else if (stack[count] == '[') {
					return -1; // 에러
				}
				else {
					flag = 1;
					temp += stack[count];
					stack[count] = 0;
					count--;
				}
			}
		}
		else if (exam[i] == ']') {
			temp = 0;
			count--;
			flag = 0;
			for (;;) {
				if (stack[count] == '[') {
					if (flag == 0) temp = 1;
					stack[count++] = temp * 3;
					break;
				}
				else if (stack[count] == '(') {
					return -1; // 에러
				}
				else {
					flag = 1;
					temp += stack[count];
					stack[count] = 0;
					count--;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += stack[i];
	}
	return sum;
}
int main()
{
	scanf("%s", exam);
	n=strlen(exam);
	int answer;
	answer = mystack();
	if (answer != -1) printf("%d", answer);
	else printf("0");
	return 0;
}