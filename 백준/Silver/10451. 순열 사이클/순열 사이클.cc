#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> adj[1010];
bool vis[1010];

void dfs(int x) {
    vis[x] = true;
    for (int y : adj[x]) {
        if (!vis[y]) dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        cin >> n;

        fill(adj, adj + 1010, vector<int>());
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }

        int ans = 0;
        fill(vis, vis + 1010, false);
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i), ans++;
        }

        cout << ans << '\n';
    }
}