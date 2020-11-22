#include<stdio.h>
#define MAX 202
int tree[MAX];
int path[1002];
int N, M;
int find(int x)
{
	if (tree[x] == x) {
		return x; // root
	}
	else {
		int p=find(tree[x]);
		tree[x] = p;
		return p;
	}
}
void Union(int x,int y)
{
	x= find(x);
	y = find(y);
	if (x != y) {
		tree[y] = x;
	}
}
int Print()
{
	int temp = find(path[0]);
	for (int i = 1; i < M; i++) {
		if (temp != find(path[i])) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
int main()
{
	int a;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i <= N; i++) {
		tree[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &a);
			if (a == 1 && i<j) {
				Union(i, j);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &path[i]);
	}
	Print();
	
	return 0;
}