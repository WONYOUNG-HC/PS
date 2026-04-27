#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> graph;
vector<vector<int>> dp;

int Panda(int y, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    graph.resize(n+2, vector<int>(n+2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> graph[i][j];

    dp.resize(n+2, vector<int>(n+2, -1));
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans = max(ans, Panda(i, j));

    cout << ans;

    return 0;
}

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int Panda(int y, int x) {
    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (graph[ny][nx] > graph[y][x])
            dp[y][x] = max(dp[y][x], Panda(ny, nx) + 1);
    }

    return dp[y][x];
}