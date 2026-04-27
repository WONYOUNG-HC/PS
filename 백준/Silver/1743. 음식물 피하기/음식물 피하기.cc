#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m, k;
bool arr[110][110], vis[110][110];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        arr[r][c] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] && !vis[i][j]) {
                queue<pii> q;
                q.emplace(i, j);
                vis[i][j] = true;

                int cnt = 1;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int *d : dir) {
                        int dy = y + d[0];
                        int dx = x + d[1];

                        if (arr[dy][dx] && !vis[dy][dx]) {
                            vis[dy][dx] = true;
                            q.emplace(dy, dx);
                            cnt++;
                        }
                    }
                }

                ans = max(ans, cnt);
            }
        }
    }

    cout << ans;
}