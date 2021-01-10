#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>
#define MINI(A,B) A>B ? B : A
using namespace std;
vector<vector<int> > edge_list;
int board[302][302], main_map[302][302];
int parents[90010];
bool visit[301][301];
int p_x[4] = { 1,-1,0,0 };
int p_y[4] = { 0,0,1,-1 };
int N, count;
void init(vector<vector<int> > land) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = land[i][j];
        }
    }
}
void DFS(int x, int y, int num_area, int height) {
    int next_x, next_y;
    main_map[x][y] = num_area;
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        next_x = x + p_x[i];
        next_y = y + p_y[i];
        if (next_x < 0 || next_x == N || next_y < 0 || next_y == N) continue;
        if (!visit[next_x][next_y] && abs(board[x][y] - board[next_x][next_y]) <= height) {
            DFS(next_x, next_y, num_area, height);
        }
    }
    return;
}
void make_edge(int V) {
    int next_x, next_y;
    int A_area, B_area, temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A_area = main_map[i][j];
            for (int k = 0; k < 4; k++) {
                next_x = i + p_x[k];
                next_y = j + p_y[k];
                if (next_x < 0 || next_x == N || next_y < 0 || next_y == N) continue;
                B_area = main_map[next_x][next_y];
                if (A_area != B_area) {
                    temp = abs(board[i][j] - board[next_x][next_y]);
                    edge_list.push_back({ A_area,B_area,temp });
                }
            }
        }
    }
}
bool comp(vector<int>& A, vector<int>& B) {
    return A[2] < B[2];
}
int find_parents(int x) {
    if (x == parents[x]) return x;
    return parents[x] = find_parents(parents[x]);
}
void union_set(int x, int y) {
    x = find_parents(x);
    y = find_parents(y);
    parents[y] = x;
}
int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int count = 1, x, y;
    N = land.size();
    init(land);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                DFS(i, j, count, height);
                count++;
            }
        }
    }
    make_edge(count);
    sort(edge_list.begin(), edge_list.end(), comp);
    //MST (Kruskal)
    for (int i = 1; i < count; i++) {
        parents[i] = i;
    }
    for (int i = 0; i < edge_list.size(); i++) {
        x = edge_list[i][0];
        y = edge_list[i][1];
        if (find_parents(x) != find_parents(y)) { // No cycle
            union_set(x, y);
            answer += edge_list[i][2];
        }
    }
    return answer;
}