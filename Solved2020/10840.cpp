#include<stdio.h>
#include<string.h>

#define MAX(A,B) A>B ? A : B
#define MIN(A,B) A<B ? A : B

char A[1502], B[1502];
int check_A[26][1502];
int check_B[26][1502];

bool check(int mid) {
	bool flag = true;

	for (int i = 0; i < strlen(A) - mid + 1; i++) {
		for (int j = 0; j < strlen(B) - mid + 1; j++) {
			flag = true;
			for (int k = 0; k <= 24; k++) {
				if ((check_A[k][i + mid - 1] - check_A[k][i - 1]) != (check_B[k][j + mid - 1] - check_B[k][j - 1])) {				
					flag = false;
					break;
				}
			}
			if (flag) {
				return true;
			}
		}
	}

	return false;
}
int solution() {
	int answer = 0;
	int start = 0, end = MIN(strlen(A), strlen(B));
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;

		bool check_by = check(mid);
		if (check_by) {
			answer = MAX(answer, mid);
			start = mid + 1;
			end = MIN(strlen(A), strlen(B));
		}
		else {
			end = mid - 1;
		}

	}

	return answer;
}

int main() {
	scanf("%s", A);
	scanf("%s", B);

	for (int i = 0; i < strlen(A); i++) {
		for (int j = 0; j <= 24; j++) {
			check_A[j][i] = check_A[j][i - 1];
		}
		check_A[A[i] - 'a'][i]++;
	}
	for (int i = 0; i < strlen(B); i++) {
		for (int j = 0; j <= 24; j++) {
			check_B[j][i] = check_B[j][i - 1];
		}
		check_B[B[i] - 'a'][i]++;
	}


	printf("%d", solution());

	return 0;
}