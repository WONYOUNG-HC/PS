#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int n, m;
vector<pii> adj[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(!c, b);
        adj[b].emplace_back(!c, a);
    }

    bool vis[1010];
    deque<pii> dq;

    fill_n(vis, 1010, false);
    int cnt = 1, mx = 0;
    dq.push_back(adj[0].front());
    vis[0] = true;
    while (!dq.empty()) {
        int cost = dq.front().first;
        int node = dq.front().second;
        dq.pop_front();

        if (vis[node])
            continue;

        vis[node] = true;
        mx += cost;
        cnt++;

        if (cnt == n + 1)
            break;

        for (pii& next : adj[node]) {
            if (!vis[next.second]) {
                next.first == 0 ? dq.push_back(next) : dq.push_front(next);
            }
        }
    }
    dq.clear();

    fill_n(vis, 1010, false);
    cnt = 1;
    int mn = 0;
    dq.push_back(adj[0].front());
    vis[0] = true;
    while (!dq.empty()) {
        int cost = dq.front().first;
        int node = dq.front().second;
        dq.pop_front();

        if (vis[node])
            continue;

        vis[node] = true;
        mn += cost;
        cnt++;

        if (cnt == n + 1)
            break;

        for (pii& next : adj[node]) {
            if (!vis[next.second]) {
                next.first == 1 ? dq.push_back(next) : dq.push_front(next);
            }
        }
    }

    cout << mx * mx - mn * mn;
}