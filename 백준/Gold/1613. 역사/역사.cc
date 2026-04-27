#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, s;
vector<int> adj[410];
bool ord[410][410], vis[410];

void dfs(int start, int cur) {
    for (int next : adj[cur]) {
        if (vis[next])
            continue;

        vis[next] = true;
        ord[start][next] = true;
        dfs(start, next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        fill_n(vis, 410, false);
        dfs(i, i);
    }

    cin >> s;
    for (int i = 0; i < s; i++) {
        int a, b;
        cin >> a >> b;

        int ans;
        if (ord[a][b]) ans = -1;
        else if (ord[b][a]) ans = 1;
        else ans = 0;

        cout << ans << '\n';
    }
}