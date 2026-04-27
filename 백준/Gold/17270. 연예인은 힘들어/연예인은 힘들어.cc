#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int v, m;
vector<pii> arr[110];
int start[2];
int dist[2][110];

void dijkstra(int d) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    fill_n(dist[d], 110, 1e9);
    
    dist[d][start[d]] = 0;
    pq.push({0, start[d]});

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (dist[d][node] < cost) {
            continue;
        }

        for (auto next : arr[node]) {
            auto [next_cost, next_node] = next;

            if (next_cost + cost < dist[d][next_node]) {
                dist[d][next_node] = next_cost + cost;
                pq.push({dist[d][next_node], next_node});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        arr[a].push_back({c, b});
        arr[b].push_back({c, a});
    }

    cin >> start[0] >> start[1];

    dijkstra(0);
    dijkstra(1);

    int min_dist = 1e9;

    for (int i = 1; i <= v; i++) {
        if (i == start[0] || i == start[1]) {
            continue;
        }

        if (dist[0][i] == 1e9 || dist[1][i] == 1e9) {
            continue;
        }

        min_dist = min(min_dist, dist[0][i] + dist[1][i]);
    }

    int ans = -1;

    for (int i = 1; i <= v; i++) {
        if (i == start[0] || i == start[1]) {
            continue;
        }

        if (dist[0][i] == 1e9 || dist[1][i] == 1e9) {
            continue;
        }

        if (dist[0][i] + dist[1][i] > min_dist) {
            continue;
        }

        if (dist[0][i] > dist[1][i]) {
            continue;
        }

        if (ans == -1) {
            ans = i;
        } else if (dist[0][i] < dist[0][ans]) {
            ans = i;
        }
    }

    cout << ans;
}