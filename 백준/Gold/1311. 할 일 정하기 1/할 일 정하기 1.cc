#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[20][20];
int dp[20][1 << 20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    fill_n(&dp[0][0], 20 * (1 << 20), 1e9);

    for (int i = 0; i < n; i++) {
        dp[0][1 << i] = arr[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < (1 << n); k++) {
                if (k & (1 << j)) {
                    dp[i][k] = min(dp[i][k], dp[i - 1][k ^ (1 << j)] + arr[i][j]);
                }
            }
        }
    }

    cout << *min_element(dp[n - 1], dp[n - 1] + (1 << n));
}