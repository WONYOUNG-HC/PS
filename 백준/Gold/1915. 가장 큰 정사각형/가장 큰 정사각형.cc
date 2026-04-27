#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxSquare(int n, int m, vector<string>& arr);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for (int i=0; i<n; i++)
        cin >> arr[i];

    cout << MaxSquare(n, m, arr);
}

int MaxSquare(int n, int m, vector<string>& arr) {
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (arr[i-1][j-1] == '1') {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                dp[i][j] += 1;

                if (dp[i][j] > ans) ans = dp[i][j];
            }
        }
    }

    return ans * ans;
}