#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> check_x;
unordered_map<int, int> check_y;
unordered_map<int, int>::iterator it;
int check(unordered_map<int, int> a) {
    for (it = a.begin(); it != a.end(); it++) {
        if (it->second != 2) {
            return it->first;
        }
    }
    return 0;
}
vector<int> solution(vector<vector<int>> v) {
    vector<int> ans;
    for (int i = 0; i < v.size(); i++) {
        check_x[v[i][0]]++;
        check_y[v[i][1]]++;
    }
    ans.push_back(check(check_x));
    ans.push_back(check(check_y));
    return ans;
}