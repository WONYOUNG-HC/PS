#include <iostream>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

struct pos {
    int day, cnt, y, x;
    pos(int day, int cnt, int y, int x) : day(day), cnt(cnt), y(y), x(x) {};
};

int n, m, k;
char arr[1010][1010];
int dist[2][15][1010][1010];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    fill_n(&arr[0][0], 1010 * 1010, '2');
    fill_n(&dist[0][0][0][0], 2 * 15 * 1010 * 1010, INF);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    queue<pos> q;
    q.emplace(0, 0, 1, 1);
    dist[0][0][1][1] = 1;

    while (!q.empty()) {
        pos cur = q.front();
        q.pop();

        if (dist[!cur.day][cur.cnt][cur.y][cur.x] > dist[cur.day][cur.cnt][cur.y][cur.x] + 1) {
            dist[!cur.day][cur.cnt][cur.y][cur.x] = dist[cur.day][cur.cnt][cur.y][cur.x] + 1;
            q.emplace(!cur.day, cur.cnt, cur.y, cur.x);
        }

        for (int* d : dir) {
            int dy = cur.y + d[0];
            int dx = cur.x + d[1];

            if (arr[dy][dx] == '1' && cur.day == 0 && cur.cnt < k) {
                if (dist[!cur.day][cur.cnt + 1][dy][dx] > dist[cur.day][cur.cnt][cur.y][cur.x] + 1) {
                    dist[!cur.day][cur.cnt + 1][dy][dx] = dist[cur.day][cur.cnt][cur.y][cur.x] + 1;
                    q.emplace(!cur.day, cur.cnt + 1, dy, dx);
                }
            }

            if (arr[dy][dx] == '0') {
                if (dist[!cur.day][cur.cnt][dy][dx] > dist[cur.day][cur.cnt][cur.y][cur.x] + 1) {
                    dist[!cur.day][cur.cnt][dy][dx] = dist[cur.day][cur.cnt][cur.y][cur.x] + 1;
                    q.emplace(!cur.day, cur.cnt, dy, dx);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= k; j++)
            ans = min(ans, dist[i][j][n][m]);

    cout << (ans == INF ? -1 : ans);
}