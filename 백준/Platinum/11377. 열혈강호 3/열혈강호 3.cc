#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
vector<int> adj[1010];
int match[1010];
bool vis[1010];

bool dfs(int x) {
    if (vis[x])
        return false;
    vis[x] = true;

    for (int y : adj[x]) {
        if (match[y] == 0 || dfs(match[y])) {
            match[y] = x;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int c; cin >> c;

        for (int j = 0; j < c; j++) {
            int w; cin >> w;
            adj[i].push_back(w);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + 1010, false);

        if (dfs(i))
            ans++;
    }

    for (int i = 1; i <= n && k > 0; i++) {
        fill(vis, vis + 1010, false);

        if (dfs(i))
            ans++, k--;
    }

    cout << ans;
}