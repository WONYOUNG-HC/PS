#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

vector<vector<int>> cost;

int Coloring(int n, int color);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    cost.resize(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    int ans = INF;
    for (int i = 0; i < 3; i++)
        ans = min(ans, Coloring(n, i));

    cout << ans;
}

int Coloring(int n, int color) {
    vector<vector<int>> dp(n, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        if (color == i)
            dp[0][i] = cost[0][i];
        else
            dp[0][i] = INF;
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    int ret = INF;
    for (int i = 0; i < 3; i++) {
        if (color != i) ret = min(ret, dp[n - 1][i]);
    }

    return ret;
}