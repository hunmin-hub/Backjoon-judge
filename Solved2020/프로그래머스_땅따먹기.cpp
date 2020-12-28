#include <iostream>
#include <vector>
#define MAXI(A,B) A>B ? A : B
using namespace std;
int Dy[100002][5];
int solution(vector<vector<int> > land)
{
    int answer = 0;
    int current_max = 0;
    for (int i = 0; i < land[0].size(); i++) {
        Dy[0][i] = land[0][i];
    }
    for (int k = 1; k < land.size(); k++) {
        for (int i = 0; i < 4; i++) {
            current_max = 0;
            for (int j = 0; j < 4; j++) {
                if (i == j) continue;
                current_max = MAXI(current_max, Dy[k - 1][j]);
            }
            Dy[k][i] = MAXI(Dy[k][i], current_max + land[k][i]);
        }
    }
    for (int i = 0; i < 4; i++) {
        answer = MAXI(answer, Dy[land.size() - 1][i]);
    }
    return answer;
}