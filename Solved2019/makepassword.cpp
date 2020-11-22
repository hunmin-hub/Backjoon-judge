#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 17
char password[MAX];
char word[MAX];
int L, C;
int DFS(char alpha,int length,int step)
{
	if (C-step<L-length) return 0;
	password[length] = alpha;
	if (length == L) {
		int check_m=0, check_j=0;
		for (int i = 1; i <=length; i++) {
			if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') {
				check_m++;
			}
			else if(password[i]>='a' && password[i]<='z') {
				check_j++;
			}
		}
		
		if (check_m >= 1 && check_j >= 2) {
			for (int i = 1; i <= length; i++) {
				printf("%c", password[i]);
			}
			printf("\n");
		}	
		return 0;
	}

	for (int i = step; i <C; i++) {
		DFS(word[i], length + 1,i+1);
	}
	return 0;
}
int main()
{
	// a,e,i,o,u ¸ðÀ½
	char t;
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &word[i]);
	}
	std::sort(word, word + C);
	DFS(0, 0,0);
	return 0;
}