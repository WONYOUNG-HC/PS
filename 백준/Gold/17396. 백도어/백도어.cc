#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int n, m;
bool ward[100010];
vector<pll> graph[100010];
ll dist[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> ward[i];
    }

    for (int i = 0; i < m; i++) {
        ll a, b, t;
        
        cin >> a >> b >> t;

        graph[a].push_back({t, b});
        graph[b].push_back({t, a});
    }

    //
    //
    //
    
    fill_n(dist, 100010, 1e14);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        ll time, cur;
        tie(time, cur) = pq.top();
        pq.pop();

        if (dist[cur] < time) {
            continue;
        }

        for (auto next : graph[cur]) {
            ll next_time, next_node;
            tie(next_time, next_node) = next;

            if (ward[next_node] && next_node != n - 1) {
                continue;
            }

            if (dist[next_node] > next_time + time) {
                dist[next_node] = next_time + time;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    if (dist[n - 1] == 1e14) {
        dist[n - 1] = -1;
    }

    cout << dist[n - 1];
} 