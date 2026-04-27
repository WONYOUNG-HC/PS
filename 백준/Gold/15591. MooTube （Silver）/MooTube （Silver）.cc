#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, q;
vector<pii> adj[5010];
bool vis[5010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        adj[p].emplace_back(r, q);
        adj[q].emplace_back(r, p);
    }

    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;

        fill_n(vis, n + 10, false);
        queue<int> q;
        q.push(v);
        vis[v] = true;

        int ans = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (pii next : adj[cur]) {
                if (!vis[next.second] && next.first >= k) {
                    q.push(next.second);
                    vis[next.second] = true;
                    ans++;
                } 
            }
        }

        cout << ans << '\n';
    }
}