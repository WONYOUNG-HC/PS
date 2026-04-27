#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[110], adj_inv[110];
int up[110], down[110];
bool vis[110];

void dfs(int x, int root) {
    vis[x] = true;
    
    for (int y : adj[x]) {
        if (!vis[y]) {
            down[root]++;
            dfs(y, root);
        }
    }
}

void dfs_inv(int x, int root) {
    vis[x] = true;

    for (int y : adj_inv[x]) {
        if (!vis[y]) {
            up[root]++;
            dfs_inv(y, root);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_inv[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        fill_n(vis, 110, false);
        dfs(i, i);
        fill_n(vis, 110, false);
        dfs_inv(i, i);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (up[i] > n / 2 || down[i] > n / 2)
            ans++;
    }

    cout << ans;
}