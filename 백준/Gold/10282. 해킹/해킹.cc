#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int, int>
#define COST first
#define TO second

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int n, d, c;
        cin >> n >> d >> c;

        vector<pii> adj[10010];
        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            adj[b].emplace_back(s, a);
        }

        int dist[10010];
        fill_n(dist, 10010, 1e9);
        dist[c] = 0;

        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.emplace(0, c);
        while (!pq.empty()) {
            int cost = pq.top().COST;
            int to = pq.top().TO;
            pq.pop();

            if (dist[to] < cost)
                continue;

            for (auto& pr : adj[to]) {
                if (dist[pr.TO] > cost + pr.COST) {
                    dist[pr.TO] = cost + pr.COST;
                    pq.emplace(dist[pr.TO], pr.TO);
                }
            }
        }

        int cnt = 0, mx = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] != 1e9) {
                cnt++;
                mx = max(mx, dist[i]);
            }
        }

        cout << cnt << ' ' << mx << '\n';
    }
}