#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[110];
int match[110];
bool vis[110];

bool DFS(int x) {
    if (vis[x])
        return false;
    vis[x] = true;

    for (int y : adj[x]) {
        if (match[y] == -1 || DFS(match[y])) {
            match[y] = x;
            return true;
        }
    }

    return false;
}

int solve() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    fill_n(match, n + 10, -1);
    int ret = 0;

    for (int i = 1; i <= n; i++) {
        fill_n(vis, n + 10, false);

        if (DFS(i))
            ret++;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve();
}