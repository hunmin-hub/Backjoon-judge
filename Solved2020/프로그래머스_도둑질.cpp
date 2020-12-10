#include <string>
#include <vector>
#define max(A,B) A>B ? A : B
using namespace std;
int Dy[1000002];
int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    //���� 1����
    Dy[1] = money[0];
    for (int i = 2; i < n; i++) {
        Dy[i] = max(Dy[i - 1], Dy[i - 2] + money[i - 1]);
    }
    answer = Dy[n - 1];
    //���� 1�� ���� (������ �� �Ȱ���)
    for (int i = 0; i <= n; i++) Dy[i] = 0;
    for (int i = 2; i <= n; i++) {
        Dy[i] = max(Dy[i - 1], Dy[i - 2] + money[i - 1]);
    }
    answer = max(answer, Dy[n]);
    return answer;
}