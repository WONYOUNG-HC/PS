#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MakeMoney(int n, int m, vector<int>& coins);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n;

        vector<int> coins(n+1);
        for (int i=1; i<=n; i++)
            cin >> coins[i];

        cin >> m;

        cout << MakeMoney(n, m, coins) << '\n';
    }

    return 0;
}

int MakeMoney(int n, int m, vector<int>& coins) {
    int dp[n+1][m+1];
    for (int i=0; i<=n; i++)
        dp[i][0] = 0;
    for (int j=0; j<=m; j++)
        dp[0][j] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            dp[i][j] = dp[i-1][j];
            if (coins[i] > j)
                continue;

            dp[i][j] += dp[i][j-coins[i]];
            if (coins[i] % j == 0)
                dp[i][j] += 1;
        }
    }

    return dp[n][m];
}