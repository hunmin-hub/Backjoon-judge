#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool used[22];
vector<int> answer;
long long factorial(int T) {
    long long calc = 1;
    for (int i = T; i >= 1; i--) {
        calc *= i;
    }
    return calc;
}
int correct_num(int n) {
    int first = 1, count = 0;
    while (true) {
        if (!used[first]) {
            count++;
        }
        if (count == n) return first;
        first++;
    }
    return -1;
}
void re(int n, long long k) {
    if (k == 0) {
        for (int i = n; i >= 1; i--) {
            int next_number = correct_num(i);
            answer.push_back(next_number);
            //cout<<next_number<<" ";
            used[next_number] = true;
        }
        return;
    }
    if (n == 1) {
        cout << correct_num(1);
        return;
    }
    long long first = factorial(n - 1);
    long long first_num = 0;
    first_num = (k / first);
    if (k % first != 0) first_num++;
    int correct_number = correct_num(first_num);
    used[correct_number] = true;
    answer.push_back(correct_number);
    //cout<<correct_number<<" ";
    long long next = k % first;
    re(n - 1, next);
}
vector<int> solution(int n, long long k) {
    re(n, k);
    return answer;
}