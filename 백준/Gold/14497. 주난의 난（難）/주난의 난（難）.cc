#include <iostream>
#include <deque>
#include <tuple>

using namespace std;
using pii = pair<int, int>;

int n, m;
char arr[310][310];
int dist[310][310];
pii start, target;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> start.first >> start.second >> target.first >> target.second;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    //
    //
    //

    deque<pii> dq;

    dq.push_back(start);
    dist[start.first][start.second] = 1;

    while (!dq.empty()) {
        int y, x;
        
        tie(y, x) = dq.front();
        dq.pop_front();

        if (make_pair(y, x) == target) {
            break;
        }

        for (int *d : dir) {
            int dy = y + d[0];
            int dx = x + d[1];

            if (!arr[dy][dx] || dist[dy][dx] > 0) {
                continue;
            }

            if (arr[dy][dx] == '1') {
                dist[dy][dx] = dist[y][x] + 1;
                dq.push_back({dy, dx});
            } else {
                dist[dy][dx] = dist[y][x];
                dq.push_front({dy, dx});
            }
        }
    }

    cout << dist[target.first][target.second];
}