#include <iostream>
#include <vector>
using namespace std;
#define MAXI(A,B) A>B ? A : B
int Dy[100010];
int N;
int re(int idx) {
    if (idx < 0) return 100002;
    return idx;
}
int Dynamic(int picked, vector<int> sticker) {
    Dy[0] = picked;
    for (int i = 1; i < N; i++) {
        Dy[i] = MAXI(Dy[i - 1], Dy[re(i - 2)] + sticker[i]);
    }
    if (picked == 0) return Dy[N - 1];
    return Dy[N - 2];
}
int solution(vector<int> sticker)
{
    int answer = 0;
    N = sticker.size();
    if (N == 1) return sticker[0];
    answer = Dynamic(sticker[0], sticker);
    answer = MAXI(answer, Dynamic(0, sticker));
    return answer;
}