#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e21
#define ll long long
#define pll pair<long long, long long>
#define COST first
#define TO second

using namespace std;

ll n, m, a, b, c;
vector<pll> adj[100010];

bool dijkstra(ll mid) {
    ll dist[100010];
    fill_n(dist, 100010, INF);
    dist[a] = 0;

    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.emplace(0, a);

    while (!pq.empty()) {
        ll cost = pq.top().COST;
        ll cur = pq.top().TO;
        pq.pop();

        if (cost > dist[cur])
            continue;
        
        for (pll& next : adj[cur]) {
            if (next.COST > mid)
                continue;
            if (cost + next.COST > c)
                continue;
            if (cost + next.COST >= dist[next.TO])
                continue;

            if (next.TO == b)
                return true;

            dist[next.TO] = cost + next.COST;
            pq.emplace(dist[next.TO], next.TO);
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> a >> b >> c;
    
    ll left = 1e9, right = 0;
    for (int i = 0; i < m; i++) {
        ll s, e, d;
        cin >> s >> e >> d;

        adj[s].emplace_back(d, e);
        adj[e].emplace_back(d, s);

        left = min(left, d);
        right = max(right, d);
    }

    ll mx = right;
    while (left <= right) {
        ll mid = (left + right) / 2;

        if (dijkstra(mid))
            right = mid - 1;
        else   
            left = mid + 1;
    }

    cout << (left > mx ? -1 : left);
}