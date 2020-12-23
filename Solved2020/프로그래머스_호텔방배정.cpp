#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> rooms;
long long find(long long x) { // 빈방의 번호를 찾아준다
    if (rooms[x] == 0) {
        return x;
    }
    return rooms[x] = find(rooms[x]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    long long now; // 현재 배정받고 싶은 방 번호
    long long now_able; // 방이 이미있을때 가장 가까운 비어있는 방번호

    for (int i = 0; i < room_number.size(); i++) {
        now = room_number[i];
        if (!rooms[now]) { // 방이 비어있다면
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