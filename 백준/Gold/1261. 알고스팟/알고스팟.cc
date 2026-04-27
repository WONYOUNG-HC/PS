#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define INF 1e9

using namespace std;

vector<vector<char>> graph;
vector<vector<int>> dist;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    graph.resize(n + 2, vector<char>(m + 2, 'n'));
    dist.resize(n + 2, vector<int>(m + 2, INF));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> graph[i][j];

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(0, 1, 1);
    dist[1][1] = 0;

    while (!pq.empty()) {
        int c = get<0>(pq.top());
        int y = get<1>(pq.top());
        int x = get<2>(pq.top());
        pq.pop();

        if (y == n && x == m)
            break;

        for (int* dir : direction) {
            int ny = y + dir[0];
            int nx = x + dir[1];

            if (graph[ny][nx] == 'n')
                continue;

            if (graph[ny][nx] == '1' && dist[ny][nx] > dist[y][x] + 1) {
                dist[ny][nx] = dist[y][x] + 1;
                pq.emplace(c + 1, ny, nx);
            }
            else if (graph[ny][nx] == '0' && dist[ny][nx] > dist[y][x]) {
                dist[ny][nx] = dist[y][x];
                pq.emplace(c, ny, nx);
            }
        }
    }

    cout << dist[n][m];
}