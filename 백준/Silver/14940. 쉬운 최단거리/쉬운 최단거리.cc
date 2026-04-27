#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 0x3fffffff

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dist;

void Bfs(int n, int m, int y, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int y, x;
    graph.resize(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                y = i; x = j;
            }
        }
    }

    Bfs(n, m, y, x);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (graph[i][j] == 0)
                cout << 0 << ' ';
            else
                cout << (dist[i][j] == INF ? -1 : dist[i][j]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}

void Bfs(int n, int m, int y, int x) {
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    dist.resize(n, vector<int>(m, INF));
    queue<pair<int, int>> q;
    dist[y][x] = 0;
    q.emplace(y, x);

    while (!q.empty()) {
        int py = q.front().first;
        int px = q.front().second;
        q.pop();

        for (int* dir : direction) {
            int ny = py + dir[0];
            int nx = px + dir[1];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (graph[ny][nx] == 0)
                continue;
            if (dist[ny][nx] != INF)
                continue;

            dist[ny][nx] = min(dist[ny][nx], dist[py][px] + 1);
            q.emplace(ny, nx);
        }
    }
}