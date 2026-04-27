#include <iostream>

using namespace std;

int k;
int arr[510], dp[510][510], sum[510];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> arr[i];
            sum[i] = arr[i] + sum[i - 1];
        }

        for (int i = 1; i <= k; i++)
            dp[i][i] = 0;

        for (int i = 1; i < k; i++) {
            for (int j = 1; i + j <= k; j++) {
                int x = j, y = j + i;
                dp[x][y] = 1e9;

                for (int c = x; c < y; c++) 
                    dp[x][y] = min(dp[x][y], dp[x][c] + dp[c + 1][y] + sum[y] - sum[x - 1]);
            }
        }

        cout << dp[1][k] << '\n';
    }
}