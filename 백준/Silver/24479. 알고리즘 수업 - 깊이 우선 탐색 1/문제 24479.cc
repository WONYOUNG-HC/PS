#include <iostream>
#include <set>

using namespace std;

int n, m, r, cnt;
set<int> adj[100010];
int vis[100010];

void dfs(int x) {
    vis[x] = ++cnt;

    bool leaf = true;
    for (int y : adj[x]) {
        if (!vis[y]) {
            dfs(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }

    dfs(r);
    for (int i = 1; i <= n; i++)
        cout << vis[i] << '\n';
}