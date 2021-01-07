#include <iostream>
#include <string>
#include <vector>
#define INF 9999999
#define MINI(A,B) A>B ? B : A
using namespace std;
// Dy[i]= t[i]까지 만들 수 있는 최소값
// Dy[i]=Dy[i-strs[j].length()]+1
int Dy[20002];
int solution(vector<string> strs, string t)
{
    bool flag = true;
    int answer = -1;
    int before_idx;
    for (int i = 1; i <= t.length(); i++) {
        Dy[i] = INF;
    }
    for (int i = 1; i <= t.length(); i++) {
        for (int j = 0; j < strs.size(); j++) {
            before_idx = i - strs[j].length();
            if (before_idx < 0) continue;
            flag = true;
            for (int k = 0; k < strs[j].length(); k++) {
                if (t[before_idx + k] != strs[j][k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                Dy[i] = MINI(Dy[i], Dy[before_idx] + 1);
            }
        }
    }
    answer = Dy[t.length()];
    if (answer == INF) answer = -1;
    return answer;
}