#include <iostream>

using namespace std;

const int inf = 1e9;

int n, m;
int arr[1010][1010];
int dp[1010][1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp[1][1] = arr[1][1];

    for (int i = 2; i <= m; i++) {
        dp[1][i] = dp[1][i - 1] + arr[1][i];
    }

    int dp_l[1010];
    int dp_r[1010];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + arr[i][j];
        }

        dp_l[1] = dp[i][1];

        for (int j = 2; j <= m; j++) {
            dp_l[j] = max(dp[i][j], dp_l[j - 1] + arr[i][j]);
        }

        dp_r[m] = dp[i][m];

        for (int j = m - 1; j >= 1; j--) {
            dp_r[j] = max(dp[i][j], dp_r[j + 1] + arr[i][j]);
        }

        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j], max(dp_l[j], dp_r[j]));
        }
    }

    cout << dp[n][m];
}