#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    vector<int> a[9];
    int answer = 0;
    int num_default = N;
    for (int i = 1; i <= 8; i++) {
        a[i].push_back(num_default);
        num_default = num_default * 10 + N;
    }
    int temp_a, temp_b, temp_c, temp_d;
    int temp;
    int first, second;
    for (int i = 2; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            if (j <= i - j) {
                for (int k = 0; k < a[j].size(); k++) {
                    for (int l = 0; l < a[i - j].size(); l++) {
                        first = a[j][k]; second = a[i - j][l];
                        if (first < second) {
                            temp = first;
                            first = second;
                            second = temp;
                        }
                        temp_a = first + second;
                        temp_b = first * second;
                        temp_c = first - second;
                        temp_d = first / second;
                        if (temp_a > 0) a[i].push_back(temp_a);
                        if (temp_b > 0) a[i].push_back(temp_b);
                        if (temp_c > 0) a[i].push_back(temp_c);
                        if (temp_d > 0) a[i].push_back(temp_d);
                    }
                }
            }
        }
        unique(a[i].begin(), a[i].end());
    }
    for (int i = 1; i <= 8; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] == number) {
                answer = i;
                return answer;
            }
        }
    }
    answer = -1;
    return answer;
}
int main()
{
    printf("%d", solution(2, 11));
    return 0;
}