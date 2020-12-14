#include<stdio.h>
#include<unordered_map>
using namespace std;
unordered_map<int, int> card;
int main() {
	int n, m,temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		card[temp]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		printf("%d ", card[temp]);
	}
	return 0;
}