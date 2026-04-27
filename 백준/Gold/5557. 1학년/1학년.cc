#include <iostream>

using namespace std;

int n, s;
int arr[110];
long long dp[110][21];

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++)
        cin >> arr[i];
    cin >> s;

    dp[0][arr[0]] = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (0 <= j + arr[i] && j + arr[i] <= 20)
                dp[i][j + arr[i]] += dp[i - 1][j]; 
            if (0 <= j - arr[i] && j - arr[i] <= 20)
                dp[i][j - arr[i]] += dp[i - 1][j];
        }
    }

    cout << dp[n - 2][s];
}