#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m, sc;
vector<int> adj[100010], inv[100010];
bool vis[100010];
int scc[100010], in_degree[100010];
stack<int> st;

void dfs(int node) {
    vis[node] = true;

    for (int next : adj[node])
        if (!vis[next]) dfs(next);

    st.push(node);
}

void dfs_inv(int node) {
    scc[node] = sc;

    for (int prev : inv[node]) {
        if (scc[prev] == 0)
            dfs_inv(prev);
        if (scc[prev] != scc[node]) {
            in_degree[sc]++;
        }
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        adj[i].clear(), inv[i].clear();
    fill_n(vis, 100010, false);
    fill_n(scc, 100010, 0);
    fill_n(in_degree, 100010, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        inv[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);

    sc = 1;
    while (!st.empty()) {
        if (scc[st.top()] == 0)
            dfs_inv(st.top()), sc++;

        st.pop();
    }

    int ans = 0;
    for (int i = 1; i < sc; i++)
        if (in_degree[i] == 0) ans++;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--)
        solve();
}