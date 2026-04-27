#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
set<vector<int>> work;
vector<vector<long long>> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    dp.resize(n + 1, vector<long long>(m + 1));

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a > c || (a == c && b > d)) {
            swap(a, c);
            swap(b, d);
        }

        work.insert({a, b, c, d});
    }

    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0 && work.find({i - 1, j, i, j}) == work.end())
                dp[i][j] += dp[i - 1][j];

            if (j > 0 && work.find({i, j - 1, i, j}) == work.end())
                dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[n][m];
}