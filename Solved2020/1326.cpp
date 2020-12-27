#include<stdio.h>
#include<queue>
using namespace std;
bool visit[10002];
int n,dis[10002],step[10002];
queue<int> v_queue;
int main() {
	int a, b,k=1;
	scanf("%d", &n);
	for (int i = 1; i <=n; i++) {
		scanf("%d", &dis[i]);
		step[i] = 99999999;
	}
	scanf("%d %d", &a, &b);
	v_queue.push(a);
	step[a] = 0;
	while (!v_queue.empty()) {
		int current = v_queue.front();
		int current_step = step[current];
		visit[current] = true;
		v_queue.pop();
		k = 1;
		for (;;) {
			int next = current + dis[current] * k;
			if (1 <= next && next <= n) {
				if (!visit[next] && step[next]>current_step+1) {
					step[next] = current_step + 1;
					v_queue.push(next);
				}
			}
			else if (next > n) {
				break;
			}
			k++;
		}
		k = -1;
		for (;;) {
			int next = current + dis[current] * k;
			if (1 <= next && next <= n) {
				if (!visit[next] && step[next] > current_step + 1) {
					step[next] = current_step + 1;
					v_queue.push(next);
				}
			}
			else if (next <=0) {
				break;
			}
			k--;
		}
	}
	if (step[b] == 99999999) {
		printf("-1");
	}
	else {
		printf("%d", step[b]);
	}
	return 0;
}