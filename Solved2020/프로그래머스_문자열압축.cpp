#include <string>
#include <vector>
#include <iostream>
#define MINI(A,B) A>B ? B : A
using namespace std;

int solution(string s) {
    bool flag = false;
    bool mask;
    int count = 0;
    string prev = "";
    string current = "";
    string temp = "";
    int answer = s.length();
    for (int k = 1; k <= s.length() / 2; k++) {
        prev = "";
        temp = "";
        for (int i = 0; i < k; i++) {
            prev += s[i];
        }
        count = 0;
        for (int i = 0; i < s.length(); i += k) {
            current = "";
            for (int j = 0; j < k; j++) {
                if (i + j >= s.length()) continue;
                current += s[i + j];
            }
            mask = prev.compare(current);
            if (!mask) { // 같다면
                count++;
                prev = current;
                continue;
            }
            if (count > 1 && mask) { // 앞에까진 같았는데 현재는 다르다면
                temp += to_string(count);
                temp += prev;
                prev = current;
                count = 1;
                continue;
            }
            if (count == 1 && mask) {// 그냥 다르다면
                temp += prev;
                prev = current;
                count = 1;
                continue;
            }
        }
        if (count > 1) {
            temp += to_string(count);
            temp += prev;
        }
        else {
            temp += prev;
        }
        answer = MINI(answer, temp.length());
    }
    return answer;
}