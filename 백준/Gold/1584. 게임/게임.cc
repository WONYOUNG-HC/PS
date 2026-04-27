#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

const int inf = 1e9;

int n, m;
int dist[510][510];
int board[510][510];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) {
            swap(x1, x2);
        }

        if(y1 > y2) {
            swap(y1, y2);
        }

        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                board[x][y] = 1;
            }
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) {
            swap(x1, x2);
        }

        if (y1 > y2) {
            swap(y1, y2);
        }

        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                board[x][y] = 2;
            }
        }
    }

    //
    //
    //

    deque<pii> dq;

    fill_n(&dist[0][0], 510 * 510, inf);
    dist[0][0] = 0;
    dq.push_back({0, 0});
    
    while (!dq.empty()) {
        int x, y;

        tie(x, y) = dq.front();
        dq.pop_front();

        if (x == 500 && y == 500) {
            break;
        }

        for (int *d : dir) {
            int dx = x + d[0];
            int dy = y + d[1];

            if (dx < 0 || dx > 500 || dy < 0 || dy > 500) {
                continue;
            }

            if (board[dx][dy] == 2) {
                continue;
            }

            if (board[dx][dy] == 1 && dist[dx][dy] > dist[x][y] + 1) {
                dist[dx][dy] = dist[x][y] + 1;
                dq.push_back({dx, dy});
            } else if (board[dx][dy] == 0 && dist[dx][dy] > dist[x][y]) {
                dist[dx][dy] = dist[x][y];
                dq.push_front({dx, dy});
            }
        }
    }

    if (dist[500][500] == inf) {
        dist[500][500] = -1;
    }

    cout << dist[500][500];
}