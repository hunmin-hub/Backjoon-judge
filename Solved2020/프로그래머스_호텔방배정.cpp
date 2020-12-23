#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> rooms;
long long find(long long x) { // ����� ��ȣ�� ã���ش�
    if (rooms[x] == 0) {
        return x;
    }
    return rooms[x] = find(rooms[x]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    long long now; // ���� �����ް� ���� �� ��ȣ
    long long now_able; // ���� �̹������� ���� ����� ����ִ� ���ȣ

    for (int i = 0; i < room_number.size(); i++) {
        now = room_number[i];
        if (!rooms[now]) { // ���� ����ִٸ�
            rooms[now] = find(now + 1);
            answer.push_back(now);
        }
        else {
            now_able = find(now);
            rooms[now_able] = find(now_able + 1);
            answer.push_back(now_able);
        }
    }

    return answer;
}