#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    int core_n = cores.size(); // 코어 개수
    int core_min = 10001;
    for (int i = 0; i < core_n; i++) {
        if (core_min > cores[i]) core_min = cores[i];
    }
    if (n <= core_n) {
        answer = n;
        return answer;
    }
    else {
        int start_now, done_now;
        int start = (n / core_n) * core_min;
        int end = n * core_min;
        int mid;
        while (start <= end) {
            start_now = 0;
            done_now = core_n;
            mid = (start + end) / 2;
            for (int i = 0; i < core_n; i++) {
                done_now += mid / cores[i];
                if (mid % cores[i] == 0) {
                    start_now++;
                }
            }
            if (n > done_now) {
                start = mid + 1;
            }
            else if (n <= done_now - start_now) {
                end = mid - 1;
            }
            else {
                int count = 0;
                for (int i = 0; i < core_n; i++) {
                    if (mid % cores[i] == 0) {
                        count++;
                    }
                    if (count == n - (done_now - start_now)) {
                        return i + 1;
                    }
                }
            }
        }
    }
    return answer;
}
int main()
{
    vector<int> a;
    a.push_back(3);
    a.push_back(2);
    a.push_back(3);
    printf("[%d]\n",solution(6,a));
    return 0;
}