#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[510], radj[510];
int p[510], c[510];
bool vis[510];

int dfs(int x) {
    vis[x] = true;

    int ret = 0;
    for (int y : adj[x]) {
        if (!vis[y]) {
            ret += dfs(y) + 1;
        }
    }

    return ret;
}

int rdfs(int x) {
    vis[x] = true;

    int ret = 0;
    for (int y : radj[x]) {
        if (!vis[y]) {
            ret += rdfs(y) + 1;
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        fill_n(vis, 510, false);
        c[i] = dfs(i);
        p[i] = rdfs(i);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
        c[i] + p[i] == n - 1 && ans++;
    
    cout << ans;
}
