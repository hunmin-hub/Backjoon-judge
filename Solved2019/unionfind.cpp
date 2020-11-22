#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 1000002
int N, M;
int a, b, c;
int tree[MAX];
int find(int x)
{
	if (x == tree[x]) {
		return x;
	}
	else {
		int p = find(tree[x]);
		tree[x] = p;
		return p;
	}
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y) {
		tree[y] = x;
	}
}
int main()
{
	int count = 0;
	int dis = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++) {
		tree[i] = i;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &c, &a, &b);
		if (c == 0) {
			Union(a, b);
		}
		else if (c == 1) {
			int a_root = find(a);
			int b_root = find(b);
			if (a_root == b_root) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}