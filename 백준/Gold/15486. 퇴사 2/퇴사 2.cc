#include <iostream>

using namespace std;
using pii = pair<int, int>;

int n;
pii arr[1500010];
int dp[1500010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    for (int i = 0; i < n; i++) {
        int fin = i + arr[i].first;
        if (fin <= n)
            dp[fin] = max(dp[fin], dp[i] + arr[i].second);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[n];
}