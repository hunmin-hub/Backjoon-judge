#include<stdio.h>
#define MAX 1002
#define MIN(a,b) ( ( (a) < (b) ) ? (a) : (b) )
int D[MAX][3];
int RGB[MAX][3];
int Dynamic(int N)
{
	D[0][0] = 0; D[0][1] = 0; D[0][2] = 0;
	for (int i = 1; i <=N; i++) {
		//Á¡È­½Ä
		D[i][0] = MIN(RGB[i][0] + D[i - 1][1], RGB[i][0] + D[i - 1][2]); // R»öÄ¥
		D[i][1] = MIN(RGB[i][1] + D[i - 1][0], RGB[i][1] + D[i - 1][2]); // G»öÄ¥ 
		D[i][2] = MIN(RGB[i][2] + D[i - 1][0], RGB[i][2] + D[i - 1][1]); // B»öÄ¥
	}
	return 0;
}
int main()
{
	int N,mini=9999999;
	scanf("%d", &N);
	for (int i = 1; i <=N; i++) {
		scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
	}
	Dynamic(N);
	
	for (int i = 0; i < 3; i++) {
		if (mini > D[N][i]) {
			mini = D[N][i];
		}
	}
	printf("%d", mini);
	return 0;
}