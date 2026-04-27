#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, ans;
vector<int> adj[510];
bool vis[510];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pair<int, int>> q;
    q.emplace(1, 0); vis[1] = true;
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cnt > 1)
            continue;

        for (int next : adj[cur]) {
            if (vis[next])
                continue;

            vis[next] = true;
            ans++;
            q.emplace(next, cnt + 1);
        }
    }

    cout << ans;
}