#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> users;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (int i = 0; i < participant.size(); i++) {
        users[participant[i]]++;
    }
    for (int i = 0; i < completion.size(); i++) {
        users[completion[i]]--;
    }
    for (int i = 0; i < participant.size(); i++) {
        if (users[participant[i]] != 0) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}