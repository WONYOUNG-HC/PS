#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> adj[210];
bool vis[210];
int city[1010];

void dfs(int x) {
    vis[x] = true;
    for (int y : adj[x]) {
        if (!vis[y]) dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a; cin >> a;

            if (a) adj[i].push_back(j);
        }
    }

    for (int i = 0; i < m; i++)
        cin >> city[i];
    
    dfs(city[0]);
    for (int i = 0; i < m; i++) {
        if (!vis[city[i]]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}