#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<long long> dp(n+1);
    for (int i=1; i<=n; i++) {
        cin >> dp[i];
        dp[i] += dp[i-1];
    }

    int i = 1, j = 0, ans = 1000000;
    while (i <= n) {
        while (i <= n && dp[i] - dp[j] < s)
            i++;
        if (dp[i] - dp[j] >= s && ans > i - j) ans = i - j;
        j++;
    }

    cout << (ans == 1000000 ? 0 : ans);
}