#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
#define MAX 100002
int N, M;

struct poketmon {
	string name;
	int number;
};

int main()
{
	vector<poketmon> v;
	poketmon p;
	string temp;
	scanf("%s", temp);
	p.name = temp;
	p.number = 1;
	printf("%s", p.name);
	/*
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", p.name);
		std::cout << p.name;
		p.number = i + 1;
		//v.push_back(p);
	}
	*/
	return 0;
}