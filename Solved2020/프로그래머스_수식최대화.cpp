#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#define MAXI(A,B) A>B ? A : B
using namespace std;
int order[3] = { 1,2,3 }; // +,-,*
long long calc(string expression, int order[]) {
    string number = "";
    string exp = "";
    vector<long long> numbers;
    vector<char> exps;
    char current_exp;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            number += expression[i];
        }
        else {
            numbers.push_back(stoi(number));
            number = "";
            exps.push_back(expression[i]);
        }
    }
    numbers.push_back(stoi(number));
    for (int k = 0; k < 3; k++) {
        if (order[k] == 3) current_exp = '*';
        else if (order[k] == 2) current_exp = '-';
        else if (order[k] == 1) current_exp = '+';
        for (int i = 0; i < exps.size(); i++) {
            long long temp;
            if (exps[i] == current_exp) {
                if (current_exp == '*') temp = numbers[i] * numbers[i + 1];
                else if (current_exp == '-') temp = numbers[i] - numbers[i + 1];
                else if (current_exp == '+') temp = numbers[i] + numbers[i + 1];
                numbers[i] = temp;
                numbers.erase(numbers.begin() + (i + 1));
                exps.erase(exps.begin() + i);
                i--;
            }
        }
    }
    return numbers[0];
}
long long solution(string expression) {
    long long answer = 0;
    do {
        answer = MAXI(answer, abs(calc(expression, order)));
    } while (next_permutation(order, order + 3));

    return answer;
}