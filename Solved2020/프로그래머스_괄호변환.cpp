#include <string>
#include <vector>

using namespace std;
bool correct_str(string p) {
    string temp = "";
    int correct_count = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') correct_count++;
        else correct_count--;
        if (correct_count < 0) {
            return false;
        }
    }
    return true;
}
string balance_str(string p) {
    string u = "";
    int balance_count = 0;
    int temp_length;
    for (int i = 0; i < p.length(); i++) {
        u += p[i];
        if (p[i] == '(') balance_count++;
        else balance_count--;
        if (balance_count == 0) {
            string v = "";
            for (int j = i + 1; j < p.length(); j++) {
                v += p[j];
            }
            if (correct_str(u)) {
                u += balance_str(v);
            }
            else {
                string temp = "";
                for (int j = 1; j <= u.length() - 2; j++) {
                    if (u[j] == '(') temp += ')';
                    else temp += '(';
                }
                return ('(' + balance_str(v) + ')' + temp);
            }
            break;
        }
    }
    return u;
}
string solution(string p) {
    string answer = "";
    answer = balance_str(p);
    return answer;
}