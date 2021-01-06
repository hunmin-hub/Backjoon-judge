#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Info {
    string name;
    string head;
    string tail;
    int number;
    int ordered;
};
vector<Info> db_files;
string to_lower(string A) {
    for (int i = 0; i < A.length(); i++) {
        A[i] = tolower(A[i]);
    }
    return A;
}
Info get_Info(string A, int nums) {
    Info file_info;
    string temp = "";
    int idx;
    file_info.name = A; // 원본 파일명
    A = to_lower(A);
    for (int i = 0; i < A.length(); i++) {
        if (A[i] >= '0' && A[i] <= '9') {
            file_info.head = temp; // HEAD
            temp = "";
            idx = i;
            break;
        }
        temp += A[i];
    }
    bool flag = true;
    for (int i = idx; i < idx + 5; i++) {
        if (!(A[i] >= '0' && A[i] <= '9')) {
            flag = false;
            file_info.number = stoi(temp); // NUMBER
            temp = "";
            idx = i;
            break;
        }
        temp += A[i];
    }
    if (flag) {
        file_info.number = stoi(temp);
        temp = "";
        idx = A.length();
    }
    for (int i = idx; i < A.length(); i++) {
        temp += A[i];
    }
    file_info.tail = temp; // TAIL
    file_info.ordered = nums;
    return file_info;
}
bool comp(const Info& A, const Info& B) {
    if (A.head.compare(B.head) == 0) {
        if (A.number == B.number) {
            return A.ordered < B.ordered;
        }
        return A.number < B.number;
    }
    return A.head < B.head;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    Info temp_file;
    for (int i = 0; i < files.size(); i++) {
        temp_file = get_Info(files[i], i + 1);
        db_files.push_back(temp_file);
    }
    sort(db_files.begin(), db_files.end(), comp);
    for (int i = 0; i < db_files.size(); i++) {
        answer.push_back(db_files[i].name);
    }
    return answer;
}