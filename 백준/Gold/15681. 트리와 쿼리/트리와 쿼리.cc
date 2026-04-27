#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<int> adj[200010];
int child[200010];
bool vis[200010];

void dfs(int x, int prev) {
    vis[x] = true;
    for (int y : adj[x]) {
        if (!vis[y]) {
            child[x]++;
            dfs(y, x);
        }
    }
    child[prev] += child[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(r, 0);

    for (int i = 0; i < q; i++) {
        int u; cin >> u;
        cout << child[u] + 1 << '\n';
    }
}