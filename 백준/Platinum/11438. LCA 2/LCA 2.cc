#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<int> arr[100010];
int dp[100010][20];
int depth[100010];

void set_parent(int parent, int cur, int level) {
    dp[cur][0] = parent;
    depth[cur] = level;
    
    for (int next : arr[cur]) {
        if (next != parent) {
            set_parent(cur, next, level + 1);
        }
    }
}

void set_dp() {
    for (int j = 1; j < 17; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

int get_lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }

    int depth_diff = depth[a] - depth[b];

    for (int i = 0; ; i++) {
        if ((depth_diff & 1) == 1) {
            a = dp[a][i];
        }

        depth_diff >>= 1;

        if (depth_diff == 0) {
            break;
        }
    }

    //
    //
    //

    if (a == b) {
        return a;
    }

    for (int i = (int)log2(depth[a]) + 1; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }

    return dp[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;

        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    //
    //
    //

    set_parent(0, 1, 0);

    //
    //
    //

    set_dp();

    //
    //
    //

    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        cout << get_lca(a, b) << '\n';
    }
}