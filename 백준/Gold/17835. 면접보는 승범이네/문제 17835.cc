#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>
#define cost first
#define to second

using namespace std;

int n, m, k;
vector<pll> adj[100010];
ll dist[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[b].emplace_back(c, a);
    }

    for (int i = 0; i < k; i++) {
        ll a; cin >> a;
        adj[0].emplace_back(0, a);
    }

    fill_n(dist, 100010, 1e18);
    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.emplace(0, 0);
    dist[0] = 0;

    while (!pq.empty()) {
        ll c = pq.top().cost;
        ll v = pq.top().to;
        pq.pop();

        if (dist[v] < c)
            continue;

        for (pll& next : adj[v]) {
            if (dist[next.to] > c + next.cost) {
                dist[next.to] = c + next.cost;
                pq.emplace(dist[next.to], next.to);
            }
        }
    }

    pll ans = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (dist[i] > ans.cost)
            ans = {dist[i], i};
    }

    cout << ans.to << '\n' << ans.cost;
}