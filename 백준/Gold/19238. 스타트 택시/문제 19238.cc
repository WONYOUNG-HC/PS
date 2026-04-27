#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m, k;
int arr[30][30];
pii cur;
pii dest[30][30];
int dist[30][30];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs() {
    fill_n(&dist[0][0], 30 * 30, 1e9);

    queue<pii> q;

    dist[cur.first][cur.second] = 0;
    q.push(cur);

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int *d : dir) {
            int dy = y + d[0];
            int dx = x + d[1];

            if (arr[dy][dx] == 1) {
                continue;
            }

            if (dist[dy][dx] <= dist[y][x] + 1) {
                continue;
            }

            dist[dy][dx] = dist[y][x] + 1;
            q.push({dy, dx});
        }
    }
}

pii find_min_dist_pos() {
    pii ret;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dest[i][j] != make_pair(0, 0) && dist[i][j] < dist[ret.first][ret.second]) {
                ret = {i, j};
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    fill_n(&arr[0][0], 30 * 30, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> cur.first >> cur.second;

    for (int i = 0; i < m; i++) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        dest[a][b] = {c, d};
    }

    //
    //
    //

    for (int i = 0; i < m; i++) {
        bfs();

        pii pos = find_min_dist_pos();
        int to_pos = dist[pos.first][pos.second];

        //
        //
        //

        cur = pos;

        bfs();

        pii target = dest[cur.first][cur.second];
        int to_target = dist[target.first][target.second];

        if (k < to_pos + to_target) {
            cout << -1;

            return 0;
        }

        cur = target;
        dest[pos.first][pos.second] = {0, 0};
        k = k - (to_pos + to_target) + (to_target * 2);
    }

    cout << k;
}