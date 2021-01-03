#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#define MINI(A,B) A>B ? B : A
#define MAXI(A,B) A>B ? A : B
using namespace std;
unordered_map<string, int> first;
unordered_map<string, int> second;
unordered_map<string, int> union_map;
unordered_map<string, int> intersection;
unordered_map<string, int>::iterator it;
string to_lower(string A) {
    for (int i = 0; i < A.length(); i++) {
        A[i] = tolower(A[i]);
    }
    return A;
}
int solution(string str1, string str2) {
    int answer = 0;
    int union_size = 0, intersection_size = 0;
    string temp = "";
    str1 = to_lower(str1);
    str2 = to_lower(str2);
    for (int i = 0; i < str1.length() - 1; i++) {
        temp = "";
        if (str1[i] >= 'a' && str1[i] <= 'z' && str1[i + 1] >= 'a' && str1[i] <= 'z') {
            temp = str1.substr(i, 2);
            first[temp]++;
        }
    }
    for (int i = 0; i < str2.length() - 1; i++) {
        temp = "";
        if (str2[i] >= 'a' && str2[i] <= 'z' && str2[i + 1] >= 'a' && str2[i + 1] <= 'z') {
            temp = str2.substr(i, 2);
            second[temp]++;
        }
    }
    for (it = first.begin(); it != first.end(); it++) {
        if (second[it->first] != 0) {
            intersection[it->first] = MINI(first[it->first], second[it->first]);
        }
        union_map[it->first] = first[it->first];
    }
    for (it = second.begin(); it != second.end(); it++) {
        union_map[it->first] = MAXI(second[it->first], union_map[it->first]);
    }
    for (it = union_map.begin(); it != union_map.end(); it++) {
        union_size += it->second;
    }
    for (it = intersection.begin(); it != intersection.end(); it++) {
        intersection_size += it->second;
    }
    //cout<<intersection_size<<" "<<union_size;
    if (union_size == 0) return 65536;
    if (intersection_size == 0) return 0;
    double zkad = (double)intersection_size / union_size;
    answer = zkad * 65536;
    return answer;
}