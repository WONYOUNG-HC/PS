#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[510];
bool tree, vis[510];

void dfs(int prev, int cur) {
    vis[cur] = true;

    for (int next : adj[cur]) {
        if (prev == next)
            continue;

        if (vis[next])
            tree = false;
        else
            dfs(cur, next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    while (true) {
        cin >> n >> m;

        if (n + m == 0)
            break;

        fill_n(adj, n + 10, vector<int>());
        fill_n(vis, n + 10, false);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i])
                continue;

            tree = true;
            dfs(0, i);
            tree && ans++;
        }

        cout << "Case " << tc << ": ";
        if (ans == 0)
            cout << "No trees.\n";
        else if (ans == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << ans << " trees.\n";

        tc++;
    }
}