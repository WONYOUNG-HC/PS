#include <iostream>
#include <algorithm>

using namespace std;

int nums[5005];
int dp[5005][5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    for (int diag = 1; diag <= n; diag++) {
        for (int i = 1; i + diag <= n; i++) {
            int j = diag + i;

            if (nums[i] == nums[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }

    cout << dp[1][n];
}