#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;
int arr[60][60];
bool vis[60][60];
vector<pii> cloud;
int dir[9][2] = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int diag[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    cloud.push_back({n, 1});
    cloud.push_back({n, 2});
    cloud.push_back({n - 1, 1});
    cloud.push_back({n - 1, 2});

    for (int cnt = 0; cnt < m; cnt++) {
        int d, s;

        cin >> d >> s;

        fill_n(&vis[0][0], 60 * 60, false);

        for (auto pos : cloud) {
            int y, x;

            tie(y, x) = pos;
 
            for (int i = 0; i < s; i++) {
                y = (y + dir[d][0] + n - 1) % n + 1;
                x = (x + dir[d][1] + n - 1) % n + 1;
            }

            arr[y][x] += 1;
            vis[y][x] = true;
        }

        cloud.clear();

        vector<pii> rain;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!vis[i][j]) {
                    continue;
                }

                for (int *dg : diag) {
                    int di = i + dg[0];
                    int dj = j + dg[1];

                    if (arr[di][dj] >= 1) {
                        rain.push_back({i, j});
                    }
                }
            }
        }

        for (auto pos : rain) {
            arr[pos.first][pos.second] += 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] >= 2 && !vis[i][j]) {
                    cloud.push_back({i, j});
                    arr[i][j] -= 2;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += arr[i][j];
        }
    }

    cout << ans;
}