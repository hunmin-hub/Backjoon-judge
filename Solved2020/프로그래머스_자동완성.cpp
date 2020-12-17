#include <string>
#include <vector>
#include <algorithm>
#define MAX(A,B) A>B ? A : B
using namespace std;
int solution(vector<string> words) {
    int answer = 0;
    int count_a, count_b, count;
    sort(words.begin(), words.end());
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].length(); j++) {
            printf("%c", words[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < words.size(); i++) {
        count_a = 0, count_b = 0;
        bool flag_a = true, flag_b = true;
        for (int j = 0; j < words[i].length(); j++) {
            if (i - 1 >= 0) {
                if (words[i - 1].length() < j) continue;
                if (words[i][j] == words[i - 1][j] && flag_a) {
                    count_a++;
                }
                else {
                    flag_a = false;
                }
            }
            if (i + 1 < words.size()) {
                if (words[i + 1].length() < j) continue;
                if (words[i][j] == words[i + 1][j] && flag_b) {
                    count_b++;
                }
                else {
                    flag_b = false;
                }
            }
        }
        flag_a = true, flag_b = true;
        count = MAX(count_a, count_b);
        if (words[i].length() == count) {
            printf("%d\n", count);
            answer += count;
        }
        else {
            answer += (count + 1);
            printf("%d\n", count + 1);
        }
    }

    return answer;
}
int main() {
    vector<string> a;
    a.push_back("abc");
    a.push_back("defa");
    a.push_back("hij");
    a.push_back("klmh");
    solution(a);
    return 0;
}