#include <iostream>

using namespace std;

int n, k, ans = 1e9;
int arr[11][11];
bool vis[11];

void dfs(int cnt, int pos, int cur) {
    if (cur > ans)
        return;

    if (cnt == n) {
        ans = min(ans, cur);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;

        vis[i] = true;
        dfs(cnt + 1, i, cur + arr[pos][i]);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int l = 0; l < n; l++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = min(arr[i][j], arr[i][l] + arr[l][j]);

    vis[k] = true;
    dfs(1, k, 0);

    cout << ans;
}