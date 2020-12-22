#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, char> require_skill;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    require_skill[skill[0]] = '-';
    for (int i = 1; i < skill.length(); i++) {
        require_skill[skill[i]] = skill[i - 1];
    }
    for (int k = 0; k < skill_trees.size(); k++) {
        bool flag = true;
        unordered_map<char, bool> user_skill; // true = 배운 스킬
        for (int i = 0; i < skill_trees[k].size(); i++) {
            char current_skill = skill_trees[k][i];
            user_skill[current_skill] = true;
            if (require_skill.count(current_skill)) { // 요구스킬이 있다면
                char check_skill = require_skill[current_skill];
                while (check_skill != '-') {
                    if (!user_skill.count(check_skill)) {
                        flag = false;
                        break;
                    }
                    current_skill = check_skill;
                    check_skill = require_skill[current_skill];
                }
                if (!flag) break;
            }
        }
        if (flag) answer++;
    }
    return answer;
}