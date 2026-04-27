#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int n, m, ans;
int arr[510][510];
bool vis[510][510];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
array<array<int, 2>, 5> block = {{{1, 1}, {0, 1}, {1, 0}, {2, 1}, {1, 2}}};

void dfs(int y, int x, int cnt, int cur) {
    if (cnt == 4) {

        ans = max(cur, ans);
        return;
    }

    vis[y][x] = true;

    for (int* d : dir) {
        int dy = y + d[0];
        int dx = x + d[1];

        if (dy < 1 || dy > n || dx < 1 || dx > m)
            continue;

        if (vis[dy][dx])
            continue;

        dfs(dy, dx, cnt + 1, cur + arr[dy][dx]);
        vis[dy][dx] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dfs(i, j, 1, arr[i][j]), vis[i][j] = false;

    for (int i = 1; i <= n; i++) {
        array<array<int, 2>, 5> b = block;

        for (int j = 1; j <= m; j++) {
            int cur = 0;
            for (int k = 0; k < 5; k++)
                cur += arr[b[k][0]][b[k][1]];

            for (int k = 1; k < 5; k++)
                ans = max(ans, cur - arr[b[k][0]][b[k][1]]);

            for (int k = 0; k < 5; k++)
                b[k][1]++;
        }

        for (int k = 0; k < 5; k++)
            block[k][0]++;
    }

    cout << ans;
}