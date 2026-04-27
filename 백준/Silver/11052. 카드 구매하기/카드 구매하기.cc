#include <iostream>

using namespace std;

int n;
int arr[1010], dp[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        dp[i] = arr[i];
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout << dp[n];
}