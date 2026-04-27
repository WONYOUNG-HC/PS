#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;

    vector<pair<int, int>> coin(k);
    for (int i = 0; i < k; i++) {
        int price, cnt;
        cin >> price >> cnt;
        coin[i].first = price;
        coin[i].second = cnt;
    }

    sort(coin.begin(), coin.end());

    vector<vector<int>> dp(k + 1, vector<int>(t + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= k; i++) {
        int price = coin[i - 1].first;
        int cnt = coin[i - 1].second;

        dp[i][0] = 1;
        for (int j = 1; j <= t; j++) {
            dp[i][j] = dp[i - 1][j];

            for (int l = 1; l <= cnt; l++) {
                if (j - (price * l) < 0)
                    break;

                dp[i][j] += dp[i - 1][j - (price * l)];
            }
        }
    }

    cout << dp[k][t];
}