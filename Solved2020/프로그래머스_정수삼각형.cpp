#include <string>
#include <vector>
using namespace std;
#define MAX(A,B) A>B ? A : B
int Dy[502][502];
// Á¡È­½Ä
// D[i][j]+=MAX(D[i-1][j],D[i-1][j-1])
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    int m = triangle[n - 1].size();
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            Dy[i + 1][j + 1] = triangle[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            Dy[i][j] += MAX(Dy[i - 1][j], Dy[i - 1][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        answer = MAX(Dy[n][i], answer);
    }
    return answer;
}