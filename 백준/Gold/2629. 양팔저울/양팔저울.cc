#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[40];
bool dp[40][40010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 40000; j++) {
            if (!dp[i - 1][j]) {
                continue;
            }

            dp[i][j] = true;
            
            if (arr[i] + j <= 40000) {
                dp[i][arr[i] + j] = true;
            }

            if (arr[i] - j >= 0) {
                dp[i][arr[i] - j] = true;
            }

            if (j - arr[i] >= 0) {
                dp[i][j - arr[i]] = true;
            }
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int w;

        cin >> w;

        cout << (dp[n][w] ? 'Y' : 'N') << ' ';
    }
}