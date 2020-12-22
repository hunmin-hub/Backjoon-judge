#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> people, int limit) {
    int answer = 0;
    int front = 0, back = people.size() - 1;
    sort(people.begin(), people.end());
    if (front == back) return 1;
    while (front < back) {
        if (people[front] + people[back] <= limit) {
            front++;
            back--;
            answer++;
        }
        else {
            back--;
            answer++;
        }
        if (front == back) {
            answer++;
            break;
        }
    }
    return answer;
}