#include <string>
#include <vector>
#define MAX(A,B) A>B ? A : B
using namespace std;
int Dy_sum[2002];
int solution(vector<int> cookie) {
    int answer = 0;
    int sum = 0;
    for (int i = 0; i < cookie.size(); i++) {
        sum += cookie[i];
        Dy_sum[i] = sum;
    }
    sum = 0;

    int check = 0;
    for (int i = 0; i < cookie.size(); i++) {
        for (int j = i + 1; j < cookie.size(); j++) {
            sum = Dy_sum[j] - Dy_sum[i - 1]; // i~j������ ��Ű ��
            if (sum % 2 == 0) { // �Ȱ��� ������ ���� ���ɼ��� ���� ��
                if (sum / 2 > answer) {
                    check = 0;
                    for (int k = i; k <= j; k++) {
                        check += cookie[k];
                        if (check == sum / 2) {
                            answer = MAX(answer, check);
                            break;
                        }
                        else if (check > sum / 2) {
                            break;
                        }
                    }
                }

            }
        }
    }
    return answer;
}