#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<vector<pair<int, int>>> graph;

void spfa(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].emplace_back(b, c);
    }

    spfa(n);
}

void spfa(int n) {
    vector<long long> dist(n + 1, INF);
    queue<int> q;
    vector<bool> in_q(n + 1);
    vector<int> cnt(n + 1);
    dist[1] = 0;
    q.push(1);
    in_q[1] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        in_q[node] = false;

        for (pair<int, int>& pr : graph[node]) {
            int next = pr.first;
            int cost = pr.second;

            if (dist[next] > dist[node] + cost) {
                dist[next] = dist[node] + cost;

                if (in_q[next])
                    continue;

                cnt[next]++;
                if (cnt[next] >= n) {
                    cout << -1;
                    return;
                }

                in_q[next] = true;
                q.push(next);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
    }
}