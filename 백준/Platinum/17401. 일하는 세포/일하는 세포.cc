#include <iostream>
#include <vector>

using namespace std;
using vvi = vector<vector<int>>;

int t, n, d;
vector<vvi> graph;
vector<vvi> dp;

vvi mat_mul(const vvi &a, const vvi &b) {
    vvi ret(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret[i][j] = (ret[i][j] + ((long long)a[i][k] * b[k][j])) % 1000000007;
            }
        }
    }

    return ret;
}

vvi mat_pow(int k) {
    if (k == 1) {
        return dp[t - 1];
    }

    vvi a = mat_pow(k / 2);
    vvi b;

    if (k % 2 == 0) {
        b = a;
    } else {
        b = mat_mul(a, dp[t - 1]);
    }

    return mat_mul(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> n >> d;

    for (int i = 0; i < t; i++) {
        vector<vector<int>> v(n, vector<int>(n));
        int m;

        cin >> m;

        for (int j = 0; j < m; j++) {
            int a, b, c;

            cin >> a >> b >> c;

            v[a - 1][b - 1] = c;
        }

        graph.push_back(v);
    }

    //
    //
    //

    dp.push_back(graph[0]);

    for (int i = 1; i < t; i++) {
        dp.push_back(mat_mul(dp[i - 1], graph[i]));
    }

    //
    //
    //

    vvi ans;

    if (d == 0) {
        ans = vvi(n, vector<int>(n));
    } else if (d < t) {
        ans = dp[d - 1];
    } else if (d % t == 0) {
        ans = mat_pow(d / t);
    } else {
        ans = mat_mul(mat_pow(d / t), dp[(d % t) - 1]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}