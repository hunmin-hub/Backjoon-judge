#include <string>
#include <vector>

using namespace std;

int Dy[15][15];
int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        Dy[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (i == j)    Dy[i][j] = Dy[i - 1][j - 1] + Dy[i - 1][j];
            else Dy[i][j] = Dy[i][j - 1] + Dy[i - 1][j];
        }
    }
    answer = Dy[n][n];
    return answer;
}
int main()
{
    printf("%d",solution(5));
    return 0;
}