#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, l, r;
int a[55][55];
bool vis[55][55];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool move() {
    memset(vis, 0, sizeof(vis));

    bool ret = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) {
                vector<pair<int, int>> v(1, {i, j});
                queue<pair<int, int>> q;
                q.emplace(i, j);
                vis[i][j] = true;
                int sum = a[i][j];

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int* d : dir) {
                        int dy = y + d[0];
                        int dx = x + d[1];

                        if (a[dy][dx] == -1 || vis[dy][dx])
                            continue;

                        int dif = abs(a[y][x] - a[dy][dx]);
                        if (l <= dif && dif <= r) {
                            ret = true;
                            q.emplace(dy, dx);
                            v.emplace_back(dy, dx);
                            vis[dy][dx] = true;
                            sum += a[dy][dx];
                        }
                    }
                }

                for (auto& pr : v)
                    a[pr.first][pr.second] = sum / v.size();
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(a, -1, sizeof(a));
    cin >> n >> l >> r; 

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    int day = 0;
    while (move()) day++;

    cout << day;
}