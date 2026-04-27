#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, x;
vector<vector<int>> graph;
vector<int> dist;

void bfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k >> x;

    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    bfs();

    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            cout << i << '\n';
            flag = true;
        }
    }

    if (!flag) cout << -1;
}

void bfs() {
    dist.resize(n + 1, -1);

    queue<int> q;
    q.push(x);
    dist[x] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : graph[node]) {
            if (dist[next] != -1)
                continue;

            dist[next] = dist[node] + 1;
            q.push(next);
        }
    }
}