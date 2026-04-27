#include <iostream>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

struct pos {
    int cnt, y, x;
    pos(int cnt, int y, int x) : cnt(cnt), y(y), x(x) {};
};

int n, m, k;
char arr[1010][1010];
int dist[15][1010][1010];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    queue<pos> q;
    q.emplace(0, 1, 1);
    fill_n(&dist[0][0][0], 15 * 1010 * 1010, INF);
    dist[0][1][1] = 1;

    while (!q.empty()) {
        pos cur = q.front();
        q.pop();

        for (int* d : dir) {
            int dy = cur.y + d[0];
            int dx = cur.x + d[1];

            if (dy < 1 || dy > n || dx < 1 || dx > m)
                continue;

            if (arr[dy][dx] == '1') {
                for (int i = cur.cnt + 1; i <= k; i++) {
                    if (dist[i][dy][dx] > dist[cur.cnt][cur.y][cur.x] + 1) {
                        dist[i][dy][dx] = dist[cur.cnt][cur.y][cur.x] + 1;
                        q.emplace(i, dy, dx);
                    }
                }
            }
            else {
                if (dist[cur.cnt][dy][dx] > dist[cur.cnt][cur.y][cur.x] + 1) {
                    dist[cur.cnt][dy][dx] = dist[cur.cnt][cur.y][cur.x] + 1;
                    q.emplace(cur.cnt, dy, dx);
                }
            }
        }
    }

    int ans = dist[0][n][m];
    for (int i = 1; i <= k; i++)
        ans = min(ans, dist[i][n][m]);

    cout << (ans == INF ? -1 : ans);
}