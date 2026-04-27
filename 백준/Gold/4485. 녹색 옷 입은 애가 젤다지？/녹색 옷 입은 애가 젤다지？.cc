#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dijkstra(vector<vector<int>>& graph, int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    while (true) {
        int n; cin >> n;
        if (n == 0)
            break;

        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> graph[i][j];

        cout << "Problem " << tc++ << ": " << dijkstra(graph, n) << '\n';
    }
}

int dijkstra(vector<vector<int>>& graph, int n) {
    int direction[4][2] = {{-1, 0}, {1, 0},
                           {0, -1}, {0, 1}};
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    pq.emplace(graph[0][0], 0, 0);

    while (!pq.empty()) {
        int cost = get<0>(pq.top());
        int y = get<1>(pq.top());
        int x = get<2>(pq.top());
        pq.pop();

        if (dist[y][x] < cost)
            continue;

        dist[y][x] = cost;
        for (int* dir : direction) {
            int dy = y + dir[0];
            int dx = x + dir[1];

            if (dy < 0 || dy >= n || dx < 0 || dx >= n)
                continue;

            if (dist[dy][dx] > cost + graph[dy][dx]) {
                dist[dy][dx] = cost + graph[dy][dx];
                pq.emplace(dist[dy][dx], dy, dx);
            }
        }
    }

    return dist[n - 1][n - 1];
}