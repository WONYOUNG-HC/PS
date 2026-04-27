#include <iostream>
#include <cstring>

using namespace std;

int m, n;
int board[505][505];
int dp[505][505];

int Route(int y, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << Route(1, 1);
}

int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int Route(int y, int x) {
    if (y == m && x == n)
        return 1;

    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0;

    for (int* dir : direction) {
        int ny = y + dir[0];
        int nx = x + dir[1];

        if (board[ny][nx] > 0 && board[ny][nx] < board[y][x])
            dp[y][x] += Route(ny, nx);
    }

    return dp[y][x];
}