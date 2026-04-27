#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int coins[n+1];
    for (int i=1; i<=n; i++)
        cin >> coins[i];

    int dp[k+1];
    for (int j=0; j<=k; j++)
        dp[j] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if (coins[i] == j)
                dp[j] += 1;

            if (coins[i] < j)
                dp[j] += dp[j-coins[i]];
        }
    }

    cout << dp[k];
}