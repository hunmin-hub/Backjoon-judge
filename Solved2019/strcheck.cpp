#include<stdio.h>
#include<string.h>
int main()
{
	char cro[201];
	int check = 0;
	scanf("%s", cro);
	for (int i = 0; i < strlen(cro); i++) {
		if (cro[i] == 'c') {
			if (cro[i + 1] == '=' || cro[i + 1] == '-') {
				i++;
			}
		}
		else if (cro[i] == 'd') {
			if (cro[i + 1] == 'z' && cro[i + 2] == '=') {
				i += 2;
			}
			else {
				if (cro[i + 1] == '-') {
					i++;
				}
			}
		}
		else if (cro[i] == 'l' && cro[i + 1] == 'j') {
			i++;
		}
		else if (cro[i] == 'n' && cro[i + 1] == 'j') {
			i++;
		}
		else if (cro[i] == 's' && cro[i + 1] == '=') {
			i++;
		}
		else if (cro[i] == 'z' && cro[i + 1] == '=') {
			i++;
		}
		check++;
	}
	printf("%d", check);
	return 0;
}