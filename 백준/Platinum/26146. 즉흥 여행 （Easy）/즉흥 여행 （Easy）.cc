#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> graph[200010];
vector<int> graph_inv[200010];
int last_finish;
bool vis[200010];

void dfs(int x) {
    vis[x] = true;

    for (int y : graph[x]) {
        if (!vis[y]) {
            dfs(y);
        }
    }

    last_finish = x;
}

void dfs_inv(int x) {
    vis[x] = true;

    for (int y : graph_inv[x]) {
        if (!vis[y]) {
            dfs_inv(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;

        cin >> u >> v;

        graph[u].push_back(v);
        graph_inv[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    fill_n(vis, n + 10, false);

    dfs_inv(last_finish);

    bool ans = true;

    for (int i = 1; i <= n; i++) {
        ans &= vis[i];
    }

    cout << (ans ? "Yes" : "No");
}