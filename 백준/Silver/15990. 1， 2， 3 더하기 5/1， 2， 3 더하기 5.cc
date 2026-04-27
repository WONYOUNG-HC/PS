#include <iostream>

using namespace std;
using ll = long long;

int n;
ll k = 1000000009;
ll dp[100010][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i <= 100000; i++) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % k;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % k;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % k;
    }

    int tc;

    cin >> tc;

    while (tc--) {
        cin >> n;

        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % k << '\n';
    }
}