#include <iostream>
#include <vector>
#include <queue>

#define INF 1e18

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, start, end, m;
    cin >> n >> start >> end >> m;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].emplace_back(e, c);
    }

    vector<int> income(n);
    for (int i = 0; i < n; i++)
        cin >> income[i];

    for (int i = 0; i < n; i++) {
        for (pair<int, int>& pr : graph[i]) {
            pr.second -= income[pr.first];
        }
    }

    vector<long long> dist(n, INF);
    vector<int> cnt(n);
    queue<int> q;
    vector<bool> in_q(n);
    q.push(start), in_q[start] = true, dist[start] = -income[start];

    while (!q.empty()) {
        int node = q.front();
        q.pop(), in_q[node] = false;

        for (pair<int, int>& pr : graph[node]) {
            int next_node = pr.first, next_cost = pr.second;

            if (dist[next_node] == -INF)
                continue;

            if (dist[next_node] > dist[node] + next_cost) {
                dist[next_node] = dist[node] + next_cost;

                if (dist[node] == -INF)
                    dist[next_node] = -INF;

                if (!in_q[next_node]) {
                    cnt[next_node]++;
                    if (cnt[next_node] >= n) {
                        dist[next_node] = -INF;
                    }

                    q.push(next_node), in_q[next_node] = true;
                }
            }
        }
    }

    if (dist[end] == INF) {
        cout << "gg";
        return 0;
    }
    if (dist[end] == -INF) {
        cout << "Gee";
        return 0;
    }

    cout << -dist[end];
}