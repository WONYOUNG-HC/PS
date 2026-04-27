#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[1010][1010];
int dp[1010][1010];
int dir[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};

int dfs(int y, int x) {
    if (y == 0 || x == 0)
        return -100;

    if (dp[y][x] >= 0)
        return dp[y][x];

    dp[y][x] = 0;

    for (int* d : dir) {
        int dy = y + d[0];
        int dx = x + d[1];

        dp[y][x] = max(dp[y][x], dfs(dy, dx));
    }

    dp[y][x] += arr[y][x];

    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fill_n(&dp[0][0], 1010 * 1010, -1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    dp[1][1] = arr[1][1];

    cout << dfs(n, m);
}