#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        temp.push_back((arr1[i] | arr2[i]));
    }
    for (int i = 0; i < n; i++) {
        string block = "";
        while (temp[i] > 0) {
            if (temp[i] % 2 == 1) block += '#';
            else block += ' ';
            temp[i] /= 2;
        }
        for (int j = block.length(); j < n; j++) {
            block += ' ';
        }
        reverse(block.begin(), block.end());
        answer.push_back(block);
    }
    return answer;
}