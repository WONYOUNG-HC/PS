#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9
#define Y first
#define X second

using namespace std;

int n, m;
vector<vector<char>> graph;
vector<vector<int>> dist_forward, dist_reverse;
vector<pair<int, int>> wall;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void Input();
void BFS(bool b);
int Distance();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    Input();

    BFS(true), BFS(false);

    cout << Distance();
}

void Input() {
    graph.resize(n + 2, vector<char>(m + 2, '1'));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == '1')
                wall.emplace_back(i, j);
        }
    }
}

void BFS(bool b) {
    vector<vector<int>>& dist = (b ? dist_forward : dist_reverse);
    dist.resize(n + 2, vector<int>(m + 2, INF));

    queue<pair<int, int>> q;
    if (b) q.emplace(1, 1), dist[1][1] = 1;
    else q.emplace(n, m), dist[n][m] = 1;

    while (!q.empty()) {
        int y = q.front().Y;
        int x = q.front().X;
        q.pop();

        for (int* dir : direction) {
            int dy = y + dir[0];
            int dx = x + dir[1];

            if (graph[dy][dx] == '0' && dist[dy][dx] > dist[y][x] + 1) {
                dist[dy][dx] = dist[y][x] + 1;
                q.emplace(dy, dx);
            }
        }
    }
}

int Distance() {
    int ret = min(dist_forward[n][m], dist_reverse[1][1]);

    for (pair<int, int>& w : wall) {
        int y = w.Y;
        int x = w.X;

        for (int* dir1 : direction) {
            for (int* dir2 : direction) {
                if (dir1 == dir2)
                    continue;

                int y1 = y + dir1[0], x1 = x + dir1[1];
                int y2 = y + dir2[0], x2 = x + dir2[1];

                ret = min(ret, dist_forward[y1][x1] + 1 + dist_reverse[y2][x2]);
                ret = min(ret, dist_forward[y2][x2] + 1 + dist_reverse[y1][x1]);
            }
        }
    }

    return ret == INF ? -1 : ret;
}