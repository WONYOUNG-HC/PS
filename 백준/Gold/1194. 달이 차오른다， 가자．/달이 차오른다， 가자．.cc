#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;
char arr[60][60];
pii start, target;
int dist[64][60][60];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fill_n(&arr[0][0], 60 * 60, '#');

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == '0') {
                start = {i, j};
                arr[i][j] = '.';
            } else if (arr[i][j] == '1') {
                target = {i, j};
            }
        }
    }

    //
    //
    //

    queue<pair<int, pii>> q;
    int ans = -1;

    fill_n(&dist[0][0][0], 64 * 60 * 60, -1);
    dist[0][start.first][start.second] = 0;
    q.push({0, start});

    while (!q.empty()) {
        int key, y, x;

        key = q.front().first;
        tie(y, x) = q.front().second;
        q.pop();

        if (arr[y][x] == '1') {
            ans = dist[key][y][x];
            break;
        }

        for (int *d : dir) {
            int dy = y + d[0];
            int dx = x + d[1];
            int nkey = key;

            if (arr[dy][dx] == '#') {
                continue;
            }

            if ('A' <= arr[dy][dx] && arr[dy][dx] <= 'F') {
                if (!(key & (1 << (arr[dy][dx] - 'A')))) {
                    continue;
                }
            }

            if ('a' <= arr[dy][dx] && arr[dy][dx] <= 'f') {
                nkey = key | (1 << (arr[dy][dx] - 'a'));
            }

            if (dist[nkey][dy][dx] == -1) {
                dist[nkey][dy][dx] = dist[key][y][x] + 1;
                q.push({nkey, {dy, dx}});
            }
        }
    }

    cout << ans;
}