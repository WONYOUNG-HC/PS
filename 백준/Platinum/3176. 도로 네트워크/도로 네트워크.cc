#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int n, k;
vector<pii> tree[100010];
int ancestor[100010][17];
pii weight[100010][17];
int level[100010];

void set_parent(int parent, int cur, int cost, int height) {
    ancestor[cur][0] = parent;
    weight[cur][0] = {cost, cost};
    level[cur] = height;

    for (auto next : tree[cur]) {
        if (next.second != parent) {
            set_parent(cur, next.second, next.first, height + 1);
        }
    }
}

void set_dp() {
    for (int j = 1; j < 17; j++) {
        for (int i = 1; i <= n; i++) {
            int node = ancestor[ancestor[i][j - 1]][j - 1];
            
            pii cost1 = weight[i][j -1];
            pii cost2 = weight[ancestor[i][j - 1]][j - 1];

            if (node == 0) {
                continue;
            }

            ancestor[i][j] = node;
            weight[i][j] = {min(cost1.first, cost2.first), max(cost1.second, cost2.second)};
        }
    }
}

pii get_lca(int a, int b) {
    if (level[a] < level[b]) {
        swap(a, b);
    }

    int level_diff = level[a] - level[b];
    int mn = 1e9;
    int mx = 0;

    for (int i = 0; ; i++) {
        if (level_diff & 1) {
            mn = min(mn, weight[a][i].first);
            mx = max(mx, weight[a][i].second);

            a = ancestor[a][i];
        }

        level_diff >>= 1;

        if (level_diff == 0) {
            break;
        }
    }

    if (a == b) {
        return {mn, mx};
    }

    for (int i = 16; i >= 0; i--) {
        if (ancestor[a][i] != ancestor[b][i]) {
            mn = min(mn, min(weight[a][i].first, weight[b][i].first));
            mx = max(mx, max(weight[a][i].second, weight[b][i].second));

            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    }

    return {min(mn, min(weight[a][0].first, weight[b][0].first)), max(mx, max(weight[a][0].second, weight[b][0].second))};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        tree[a].push_back({c, b});
        tree[b].push_back({c, a});
    }

    set_parent(0, 1, 0, 0);

    set_dp();

    cin >> k;

    for (int i = 0; i < k; i++) {
        int a, b;

        cin >> a >> b;

        auto ans = get_lca(a, b);
 
        cout << ans.first << ' ' << ans.second << '\n';
    }
}