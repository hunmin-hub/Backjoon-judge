#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    int temp, count = 0;
    do {
        temp = n % 3;
        n /= 3;
        if (temp == 0) {
            n--;
            temp = 4;
        }
        answer.insert(count++, 1, temp + '0');
    } while (n > 0);
    if (n > 0 && n <= 4) {
        answer.insert(count++, 1, n + '0');
    }
    reverse(answer.begin(), answer.end());
    return answer;
}