#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> conc;
string wears[35];
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int count = 0;
    for (int i = 0; i < clothes.size(); i++) {
        if (conc[clothes[i][1]] == 0) {
            wears[count++] = clothes[i][1];
        }
        conc[clothes[i][1]]++;
    }
    for (int i = 0; i < count; i++) {
        answer *= (conc[wears[i]] + 1);
    }
    answer--;
    return answer;
}