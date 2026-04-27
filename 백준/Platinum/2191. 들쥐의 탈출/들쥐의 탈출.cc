#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define pdd pair<double, double>
#define X first
#define Y second

using namespace std;

int n, m, s, v;
pdd a[110], b[110];
vector<int> adj[110];
int match[110];
bool vis[110];

bool dfs(int x) {
    if (vis[x])
        return false;
    vis[x] = true;

    for (int y : adj[x]) {
        if (match[y] == -1 || dfs(match[y])) {
            match[y] = x;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s >> v;
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;
    for (int i = 0; i < m; i++)
        cin >> b[i].X >> b[i].Y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double dist = sqrt(((a[i].X - b[j].X) * (a[i].X - b[j].X)) + ((a[i].Y - b[j].Y) * (a[i].Y - b[j].Y)));

            if (dist <= s * v)
                adj[i].push_back(j);
        }
    }

    int cnt = 0;
    fill(match, match + m, -1);
    for (int i = 0; i < n; i++) {
        fill(vis, vis + n, false);

        if (dfs(i))
            cnt++;
    }

    cout << n - cnt;
}