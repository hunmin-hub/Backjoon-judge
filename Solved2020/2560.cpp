#include<stdio.h>
#define MAX 1000002
int Dy[MAX][3]; // 0:유아, 1:성체 , 2:고자
int a, b, d, N;

void Dp() {
	Dy[0][0] = 1;
	Dy[a][0]--;
	Dy[a][1]++;
	Dy[b][1]--; Dy[b][2]++;
	Dy[d][2]--;
	for (int i = 1; i <= N; i++) {
		Dy[i][1] += Dy[i - 1][1];
		Dy[i][2] += Dy[i - 1][2];
		Dy[i][0] += Dy[i - 1][0] + Dy[i][1];
		Dy[i][0] = (Dy[i][0]+10000) % 1000;
		Dy[i][1] = (Dy[i][1]+10000) % 1000;
		Dy[i][2] = (Dy[i][2]+10000) % 1000;
		//-------------------------------------------------------------------------------//
		//Dy[i][1] : i일에 새롭게 태어날 유아들
		if (i + a <= N) {
			Dy[i + (a)][0] -= Dy[i][1]; // a일 후 성체된 유아들 제거
			Dy[i + (a)][1] += Dy[i][1]; //a일 후 성체가 될 유아들을 성체수로 증가
		}
		if (i + b <= N) {
			Dy[i + b][1] -= Dy[i][1]; // b일 후 고자된 애들 b일 후 성체수 감소
			Dy[i + b][2] += Dy[i][1]; // b일 후 고자된 애들 b일 후 고자수 증가
		}
		if (i + d <= N) {
			Dy[i + d][2] -= Dy[i][1]; // d일 후 죽을 애들 d일 후 고자수 감소(무조건 고자가 된 후 죽으므로)
		}
	}
}
void print() {
	long long answer = 0;
	for (int i = 0; i < 3; i++) {
		answer += Dy[N][i];

	}
	answer %= 1000;
	printf("%d", answer);
}
int main() {
	scanf("%d %d %d %d", &a, &b, &d, &N); // a일 후 성체 / b일 후 복제 불가 / d일 후 사망
	Dp();
	print();
	return 0;
}