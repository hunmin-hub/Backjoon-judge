#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

struct Meet {
	int begin;
	int end;
};

bool cmp(Meet f, Meet s)
{
	if (f.end == s.end) {
		return f.begin < s.begin;
	}
	else {
		return f.end < s.end;
	}
}
int main()
{
	int N;
	scanf("%d", &N);

	vector<Meet> table(N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &table[i].begin, &table[i].end);
	}

	sort(table.begin(), table.end(), cmp);

	int endtime = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (endtime <= table[i].begin) {
			endtime = table[i].end;
			count++;
		}
	}
	printf("%d", count);
	return 0;
}