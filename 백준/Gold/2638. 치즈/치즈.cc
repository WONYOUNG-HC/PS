#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;
int arr[110][110];
int cnt[110][110];
vector<pii> edge;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        edge.push_back({i, 0});
        edge.push_back({i, m + 1});

        if (i == 0 || i == n + 1) {
            for (int j = 1; j <= m; j++) {
                edge.push_back({i, j});
            }
        }
    }

    int ans = -1;
    vector<pii> melt;

    do {
        for (auto pr : melt) {
            int y, x;
            tie(y, x) = pr;

            arr[y][x] = 0;
        }

        melt.clear();
        fill_n(&cnt[0][0], 110 * 110, 0);

        queue<pii> q;

        for (auto pr : edge) {
            q.push(pr);
        }

        while (!q.empty()) {
            int y, x;
            tie(y, x) = q.front();

            q.pop();

            for (int *d : dir) {
                int dy = y + d[0];
                int dx = x + d[1];

                if (dy < 1 || dy > n || dx < 1 || dx > m) {
                    continue;
                }

                if (arr[dy][dx] == 2) {
                    continue;
                }

                cnt[dy][dx] += 1;

                if (arr[dy][dx] == 1 && cnt[dy][dx] == 2) {
                    melt.push_back({dy, dx});
                } else if (arr[dy][dx] == 0 && cnt[dy][dx] == 1) {
                    q.push({dy, dx});
                }
            }
        }

        ans += 1;
    } while (!melt.empty());

    cout << ans;
}