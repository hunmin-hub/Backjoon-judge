#include <iostream>
#include <math.h>
using namespace std;
int solution(int n, int a, int b)
{
    int answer = 0;
    int depth = (int)floor(log2(n));
    if (a > b) swap(a, b);
    for (int i = 0; i < depth; i++) {
        a = (int)ceil((double)a / 2);
        b = (int)ceil((double)b / 2);
        if (a == b) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}