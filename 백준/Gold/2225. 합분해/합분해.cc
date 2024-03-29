#include <iostream>

using namespace std;

int n, k;
int dp[210][210];

int main() {
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
        dp[1][i] = 1;
    for (int i = 0; i <= k; i++)
        dp[i][0] = 1;
    
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= 1000000000;
        }
    }

    cout << dp[k][n];
}