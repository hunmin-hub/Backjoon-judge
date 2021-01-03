#include <string>
#include <iostream>
using namespace std;
bool visit[11][11][11][11]; // (ax,ay)->(x,y) 
int solution(string dirs) {
    // (0,0) - (10,10)
    // √‚πﬂ (5,5) 
    int answer = 0;
    int x = 5, y = 5;
    int b_x, b_y;
    for (int i = 0; i < dirs.length(); i++) {
        b_x = x; b_y = y;
        if (dirs[i] == 'U') {
            if (x + 1 > 10) continue;
            x += 1;
        }
        else if (dirs[i] == 'D') {
            if (x - 1 < 0) continue;
            x -= 1;
        }
        else if (dirs[i] == 'R') {
            if (y + 1 > 10) continue;
            y += 1;
        }
        else if (dirs[i] == 'L') {
            if (y - 1 < 0) continue;
            y -= 1;
        }
        //cout<<"("<<b_x<<","<<b_y<<")"<<"->"<<"("<<x<<","<<y<<")"<<" ";
        if (!visit[b_x][b_y][x][y] && !visit[x][y][b_x][b_y]) {
            visit[b_x][b_y][x][y] = true;
            visit[x][y][b_x][b_y] = true;
            answer++;
        }
    }
    return answer;
}