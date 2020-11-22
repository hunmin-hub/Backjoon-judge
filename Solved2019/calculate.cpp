#include<stdio.h>
#define MAX 100
int number[MAX];
int check[MAX];
char cc[MAX];
int cf = 0, nf = 0;
int maxi = -2147483648;
int pro_cal(int cf,int nf,int qnumber[],char qcc[],int qcheck[])
{
	char temp_c[MAX];
	int temp_n[MAX];
	int temp_check[MAX];
	int t_cf, t_nf;
	t_cf = cf;
	t_nf = nf;
	for (int i = 0; i < t_cf; i++) {
		temp_c[i] = qcc[i];
		temp_check[i] = qcheck[i];
	}
	for (int i = 0; i < t_nf; i++) {
		temp_n[i] = qnumber[i];
	}
	int temp = 0;
	for (int i = 0; i < t_cf; i++) {
		if (temp_check[i] == 1) {
			if (temp_c[i] == '*') {
				temp_n[i]=temp_n[i] * temp_n[i + 1];
			}
			else if (temp_c[i] == '-') {
				temp_n[i]=temp_n[i] - temp_n[i + 1];
			}
			else if (qcc[i] == '+') {
				temp_n[i]= temp_n[i] + temp_n[i + 1];
			}
			for (int j = i + 1; j < nf; j++) {
				temp_n[j] = temp_n[j + 1];
			}
			for (int j = i; j < cf; j++) {
				temp_c[j] = temp_c[j + 1];
				temp_check[j] = temp_check[j + 1];
			}
			t_nf--;
			t_cf--;
		}
	}
	temp = temp_n[0];
	for (int i = 0; i < t_cf; i++) {
		if (temp_c[i] == '+') {
			temp = temp + temp_n[i + 1];
		}
		else if (temp_c[i] == '-') {
			temp = temp - temp_n[i + 1];
		}
		else if (temp_c[i] == '*') {
			temp = temp * temp_n[i + 1];
		}
	}
	
	return temp;
}
int caseby(int flag, int count)
{
	if (count > -1) {
		int temper;
		if (count == cf) {
			temper = pro_cal(cf, nf, number, cc, check);
			if (maxi < temper) {
				maxi = temper;
			}
			return 0;
		}
		check[count] = flag;
	}
	caseby(0, count + 1);
	if(flag==0) caseby(1, count + 1);
	return 0;
}
int main()
{
	int n;
	char input[MAX];
	int tcf, tnf;
	scanf("%d", &n);
	scanf("%s", input);
	for (int i = 0; i < n; i++) {
		if (input[i] == '*') {
			cc[cf++] = '*';
		}
		else if (input[i] == '-') {
			cc[cf++] = '-';
		}
		else if (input[i] == '+') {
			cc[cf++] = '+';
		}
		else {
			number[nf++] = input[i] - 48;
		}
	}
	tcf = cf;
	tnf = nf;

	caseby(0, -1);
	printf("%d", maxi);
	return 0;
}