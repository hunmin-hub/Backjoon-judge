#include <string>
#include <vector>
#include <iostream>
using namespace std;
int Dy[1002][1002];
int pattern[3][2] = { {1,0},{0,1},{-1,-1} };
vector<int> solution(int n) {
    vector<int> answer;
    int number = 1;
    int count = 0;
    int cx = 0, cy = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            if (i == j) {
                count++;
                if (count == 3) count = 0;
            }
            //cout<<"("<<cx<<","<<cy<<")";
            Dy[cx][cy] = number++;
            cx += pattern[count][0];
            cy += pattern[count][1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Dy[i][j] == 0) continue;
            answer.push_back(Dy[i][j]);
        }
    }
    return answer;
}