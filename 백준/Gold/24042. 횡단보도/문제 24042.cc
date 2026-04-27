#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m;
vector<pair<ll, ll>> adj[100010];
ll dist[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        adj[a].emplace_back(i, b);
        adj[b].emplace_back(i, a);
    }

    fill_n(dist, n + 10, 1e20);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.emplace(0, 1);
    dist[1] = 0;

    while (!pq.empty()) {
        ll cur_time = pq.top().first;
        ll cur_pos = pq.top().second;
        pq.pop();

        if (cur_time > dist[cur_pos])
            continue;

        for (auto next : adj[cur_pos]) {
            ll cost = ((m - cur_time % m) + next.first) % m + 1;

            if (dist[next.second] > cur_time + cost) {
                dist[next.second] = cur_time + cost;
                pq.emplace(cur_time + cost, next.second);
            }
        }
    }

    cout << dist[n];
}