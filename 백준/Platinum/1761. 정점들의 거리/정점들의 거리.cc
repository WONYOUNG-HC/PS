#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int n, m;
vector<pii> adj[40010];
pii dp[40010][20];
int level[40010];

void init(int cur, int prev, int cost, int depth) {
    dp[cur][0] = {cost, prev};
    level[cur] = depth;

    for (auto next : adj[cur]) {
        auto [next_cost, next_node] = next;

        if (next_node != prev) {
            init(next_node, cur, next_cost, depth + 1);
        }
    }
}

void make_dp() {
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (dp[dp[i][j - 1].second][j - 1].second == 0) {
                continue;
            }

            dp[i][j].first = dp[i][j - 1].first + dp[dp[i][j - 1].second][j - 1].first;
            dp[i][j].second = dp[dp[i][j - 1].second][j - 1].second;
        }
    }
}

int lca_length(int u, int v) {
    if (level[u] < level[v]) {
        swap(u, v);
    }

    int length = 0;
    int diff = level[u] - level[v];

    for (int i = 0; i < 20; i++) {
        if (diff == 0) {
            break;
        }

        if (diff & 1) {
            length += dp[u][i].first;
            u = dp[u][i].second;
        }

        diff >>= 1;
    }

    if (u == v) {
        return length;
    }

    for (int i = 0; i < 20; i++) {
        int k = 20 - i - 1;

        if (dp[u][k].second != dp[v][k].second) {
            length += dp[u][k].first + dp[v][k].first;
            u = dp[u][k].second;
            v = dp[v][k].second;
        }
    }

    return length + dp[u][0].first + dp[v][0].first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v, c;

        cin >> u >> v >> c;

        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    init(1, 0, 0, 1);

    make_dp();

    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;

        cin >> u >> v;

        cout << lca_length(u, v) << '\n';
    }
}