#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int> > bridge; // first:무게, second:들어간 시간
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int c_bridge_weight = 0;
    int time = 0;
    for (int i = 0; i < truck_weights.size(); i++) {
        if (c_bridge_weight + truck_weights[i] <= weight && bridge.size() + 1 <= bridge_length) {
            c_bridge_weight += truck_weights[i];
            time++;
            bridge.push(make_pair(truck_weights[i], time));
        }
        else {
            int last_truck;
            while (true) {
                if (c_bridge_weight + truck_weights[i] <= weight && bridge.size() + 1 <= bridge_length) {
                    break;
                }
                c_bridge_weight -= bridge.front().first;
                last_truck = bridge.front().second;
                bridge.pop();
            }
            if (time >= last_truck + bridge_length) time++;
            else time = last_truck + bridge_length;
            c_bridge_weight += truck_weights[i];
            bridge.push(make_pair(truck_weights[i], time));
        }
    }
    answer = time + bridge_length;
    return answer;
}