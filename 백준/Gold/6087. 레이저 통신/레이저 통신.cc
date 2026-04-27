#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int inf = 1e9;

int w, h;
char arr[110][110];
int dist[4][110][110];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> h;

    pii start, end;

    fill_n(&arr[0][0], 110 * 110, '*');

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'C' && start == make_pair(0, 0)) {
                start = {i, j};
                arr[i][j] = '.';
            } else if (arr[i][j] == 'C' && start != make_pair(0, 0)) {
                end = {i, j};
                arr[i][j] = '.';
            }
        }
    }

    fill_n(&dist[0][0][0], 4 * 110 * 110, inf);

    priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> pq;

    for (int i = 0; i < 4; i++) {
        dist[i][start.first][start.second] = 0;
        pq.push({{0, i}, start});
    }

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        auto [cost, d] = cur.first;
        auto [y, x] = cur.second;

        if (dist[d][y][x] < cost) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            if (abs(d - i) == 2) {
                continue;
            }

            int dy = y + dir[i][0];
            int dx = x + dir[i][1];

            if (arr[dy][dx] == '*') {
                continue;
            }

            if (dist[i][dy][dx] > cost + (d != i)) {
                dist[i][dy][dx] = cost + (d != i);
                pq.push({{dist[i][dy][dx], i}, {dy, dx}});
            }
        }
    }

    int ans = inf;

    for (int i = 0; i < 4; i++) {
        ans = min(ans, dist[i][end.first][end.second]);
    }

    cout << ans;
}