#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[20010];
int dv[20010];
string ans;

void dfs(int x) {
    for (int y : adj[x]) {
        if (dv[y] == dv[x]) {
            ans = "NO";
            return;
        }

        if (dv[y] == 0) {
            dv[y] = dv[x] * -1;
            dfs(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int v, e;
        cin >> v >> e;

        fill_n(adj, v + 10, vector<int>());
        fill_n(dv, v + 10, 0);
        ans = "YES";

        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= v; i++) {
            if (ans == "NO")
                break;
            
            if (dv[i] != 0)
                continue;

            dv[i] = 1;
            dfs(i);
        }

        cout << ans << '\n';
    }
}