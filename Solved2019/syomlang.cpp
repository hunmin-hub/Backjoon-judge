#include<stdio.h>
#include<string.h>
int main()
{
	char lang[3001];
	scanf("%s", lang);
	for (i = 0; i < strlen(lang); i+=2) {
		for (j = i + 2; j < strlen(lang); j+=2) {
			if (lang[i] == lang[j] && lang[i + 1] == lang[j + 1]) {
				
			}
		}
	}
	return 0;
}