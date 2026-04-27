#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> city(n + 1);
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b)
            city[a].emplace_back(b, c);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));



    for (int i = 1; i <= n; i++) {
        for (pair<int, int>& pr : city[i]) {
            int next = pr.first;
            int cost = pr.second;

            for (int j = 1; j < m; j++) {
                if (i == 1 || dp[i][j] > 0)
                    dp[next][j + 1] = max(dp[next][j + 1], dp[i][j] + cost);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = max(ans, dp[n][i]);

    cout << ans;
}