#include <string>
#include <vector>
#include <iostream>
int number[22];
int N;
int answer = 0;
using namespace std;
int DFS(int current, int next_num, int vertex, int target) {
    current += next_num;
    next_num = number[vertex + 1];
    if (current == target && vertex == N) {
        cout << "!" << " ";
        answer++;
        return 0;
    }
    if (vertex == N) return 0;

    DFS(current, next_num * (-1), vertex + 1, target);
    DFS(current, next_num, vertex + 1, target);
}
int solution(vector<int> numbers, int target) {
    N = numbers.size();
    for (int i = 1; i <= N; i++) number[i] = numbers[i - 1];
    DFS(0, 0, 0, target);
    return answer;
}
int main() {
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    printf("%d",solution(a, 3));
    return 0;
}