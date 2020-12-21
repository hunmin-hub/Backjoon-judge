#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, string> mrkim;

string solution(vector<string> seoul) {
    string answer = "�輭���� ";
    for (int i = 0; i < seoul.size(); i++) {
        mrkim[seoul[i]] = to_string(i);
    }
    string key = "Kim";
    answer += mrkim[key];
    answer += "�� �ִ�";
    return answer;
}