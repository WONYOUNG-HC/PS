#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<int> adj[100010], adj_inv[100010];
int up[100010], down[100010];
bool vis[100010];

void dfs(int x) {
    vis[x] = true;
    
    for (int y : adj[x]) {
        if (!vis[y]) {
            down[k]++;
            dfs(y);
        }
    }
}

void dfs_inv(int x) {
    vis[x] = true;

    for (int y : adj_inv[x]) {
        if (!vis[y]) {
            up[k]++;
            dfs_inv(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_inv[b].push_back(a);
    }

    dfs(k);
    dfs_inv(k);

    cout << up[k] + 1 << ' ' << n - down[k];
}