#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;
int arr[110][110];
bool vis[110][110];
vector<pii> edge;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fill_n(&arr[0][0], 110 * 110, -1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        edge.push_back({i, 1});
        edge.push_back({i, m});
    }

    for (int i = 1 + 1; i <= m - 1; i++) {
        edge.push_back({1, i});
        edge.push_back({n, i});
    }

    //
    //
    //

    int time = 0;
    int cheese = 0;

    while (true) {
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 1) {
                    cnt += 1;
                }
            }
        }

        if (cnt == 0) {
            break;
        }

        cheese = cnt;

        //
        //
        //

        queue<pii> q;
        vector<pii> melt;

        fill_n(&vis[0][0], 110 * 110, false);

        for (auto pr : edge) {
            vis[pr.first][pr.second] = true;
            q.push(pr);
        }

        while (!q.empty()) {
            int y, x;
            auto pr = q.front();
            
            q.pop();

            tie(y, x) = pr;

            if (arr[y][x] == 1) {
                melt.push_back({y, x});
                continue;
            }

            for (int *d : dir) {
                int dy = y + d[0];
                int dx = x + d[1];

                if (arr[dy][dx] == -1) {
                    continue;
                }

                if (vis[dy][dx]) {
                    continue;
                }

                vis[dy][dx] = true;
                q.push({dy, dx});
            }
        }

        for (auto pr : melt) {
            arr[pr.first][pr.second] = 0;
        }

        time += 1;
    }

    cout << time << '\n' << cheese;
}