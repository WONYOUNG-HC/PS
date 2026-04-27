#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

vector<vector<pair<int, int>>> edge;

void BellmanFord(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    edge.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].emplace_back(v, -w);
    }

    BellmanFord(n);
}

void BellmanFord(int n) {
    vector<int> dist(n + 1, INF);
    vector<int> prev(n + 1);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= n; j++) {
            for (pair<int, int>& pr : edge[j]) {
                int v = pr.first, w = pr.second;

                if (dist[j] != INF && dist[j] + w < dist[v]) {
                    dist[v] = dist[j] + w;
                    prev[v] = j;
                }
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        for (pair<int, int>& pr : edge[j]) {
            int v = pr.first, w = pr.second;

            if (dist[j] != INF && dist[j] + w < dist[v])
                dist[v] = -INF;
        }
    }

    if (dist[n] == INF || dist[n] == -INF) {
        cout << -1;
        return;
    }

    vector<int> stack = {n, prev[n]};
    while (stack.back() != 1)
        stack.push_back(prev[stack.back()]);

    for (auto ri = stack.rbegin(); ri != stack.rend(); ri++)
        cout << *ri << ' ';
}