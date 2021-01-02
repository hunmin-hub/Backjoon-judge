#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <unordered_map>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool checking(vector<string> data, string A) {
    unordered_map<char, int> batch;
    for (int i = 0; i < A.length(); i++) {
        batch[A[i]] = i + 1;
    }
    for (int i = 0; i < data.size(); i++) {
        int a = batch[data[i][0]];
        int b = batch[data[i][2]];
        int dis = data[i][4] - '0';
        if (data[i][3] == '=') { // 거리가 dis인 경우
            if (abs(a - b) - 1 != dis) return false;
        }
        else if (data[i][3] == '>') { // 거리가 dis보다 큰 경우
            if (abs(a - b) - 1 <= dis) return false;
        }
        else if (data[i][3] == '<') { // 거리가 dis보다 작은 경우
            if (abs(a - b) - 1 >= dis) return false;
        }
    }
    return true;
}
int solution(int n, vector<string> data) {
    int answer = 0;
    string photo = "ACFJMNRT";
    do {
        if (checking(data, photo)) answer++;
    } while (next_permutation(photo.begin(), photo.end()));
    return answer;
}