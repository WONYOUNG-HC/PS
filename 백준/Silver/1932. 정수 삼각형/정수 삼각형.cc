#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(int)*(n+1)*(n+1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cin >> dp[i][j];
            dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    cout << *max_element(dp[n]+1, dp[n]+n+1);
}