#include <iostream>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int dp[n+1][n+1];
    memset(dp, 0, sizeof(int)*(n+1)*(n+1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> dp[i][j];
            dp[i][j] += dp[i][j-1];
        }
    }

    int x1, y1, x2, y2;
    for (int i=0; i<m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        int sum = 0;
        for (int j=x1; j<=x2; j++)
            sum += dp[j][y2] - dp[j][y1-1];

        cout << sum << '\n';
    }
}