#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[1010];
int match[1010];
bool vis[1010];

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

        adj[i].clear();
        for (int j = a; j <= b; j++)
            adj[i].push_back(j);
    }

    fill_n(match, n + 10, -1);
    int ret = 0;

    for (int i = 1; i <= m; i++) {
        fill_n(vis, m + 10, false);

        if (DFS(i))
            ret++;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--)
        cout << solve() << '\n';
}