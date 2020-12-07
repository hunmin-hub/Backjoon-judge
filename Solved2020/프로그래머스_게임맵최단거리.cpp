#include<vector>
using namespace std;

int visit[102][102];
int map[102][102];
int step[102][102];
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
vector<int> maps_x, maps_y, maps_dis;
int n, m;
bool flag = false;
int BFS(int x, int y, int dis) {
    step[x][y] = dis;
    if (x == n && y == m) {
        flag = true;
        return 0;
    }
    else {
        for (int i = 0; i < 4; i++) {
            int next_x = x + xx[i];
            int next_y = y + yy[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
                if (visit[next_x][next_y] == 0 && map[next_x][next_y] == 1 && step[next_x][next_y] > step[x][y] + 1) {
                    visit[next_x][next_y] = 1;
                    maps_x.push_back(next_x);
                    maps_y.push_back(next_y);
                    maps_dis.push_back(dis + 1);
                }
            }
        }
    }
    return 0;
}
int solution(vector<vector<int>> maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = maps[i][j];
            step[i][j] = 10001;
        }
    }
    maps_x.push_back(0);
    maps_y.push_back(0);
    maps_dis.push_back(1);
    visit[0][0] = 1;
    while (!maps_x.empty() && !maps_y.empty() && !maps_dis.empty()) {
        if (flag) break;
        BFS(maps_x.front(), maps_y.front(), maps_dis.front());
        maps_x.erase(maps_x.begin());
        maps_y.erase(maps_y.begin());
        maps_dis.erase(maps_dis.begin());
    }
    answer = step[n - 1][m - 1];
    if (answer == 10001) answer = -1;
    return answer;
}