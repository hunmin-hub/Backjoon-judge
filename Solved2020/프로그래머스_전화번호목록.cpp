#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, bool> phone_num;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string check;
    for (int i = 0; i < phone_book.size(); i++) {
        phone_num[phone_book[i]] = true;
    }
    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 0; j < phone_book[i].length(); j++) {
            check = phone_book[i].substr(0, j);
            if (phone_num[check]) {
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}