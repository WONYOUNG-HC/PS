#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;

enum {NONE, TOMB, GHOST};

const int INF = 1e9;
const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int w, h;
int arr[40][40];
int g, e;
vi ghost[40][40];
int dist[40][40];
bool inq[40][40];
int cnt[40][40];
int ans;

bool spfa() {
    fill_n(&dist[0][0], 40 * 40, INF);
    fill_n(&inq[0][0], 40 * 40, false);
    fill_n(&cnt[0][0], 40 * 40, 0);
    ans = -1;

    queue<pii> q;

    dist[0][0] = 0;
    inq[0][0] = true;
    q.push({0, 0});

    while (!q.empty()) {
        pii cur = q.front();
        int y = cur.first;
        int x = cur.second;

        q.pop();
        inq[y][x] = false;

        if (y == h - 1 && x == w - 1) {
            continue;
        }

        if (arr[y][x] == GHOST) {
            int cost = ghost[y][x][0];
            int ny = ghost[y][x][1];
            int nx = ghost[y][x][2];

            if (dist[y][x] + cost < dist[ny][nx]) {
                dist[ny][nx] = dist[y][x] + cost;

                if (!inq[ny][nx]) {
                    q.push({ny, nx});
                    inq[ny][nx] = true;
                    cnt[ny][nx] += 1;

                    if (cnt[ny][nx] >= w * h)  {
                        return false;
                    }
                }
            }
        } else {
            for (const int *d : DIR) {
                int ny = y + d[0];
                int nx = x + d[1];

                if (ny < 0 || ny > h - 1 || nx < 0 || nx > w - 1) {
                    continue;
                }

                if (arr[ny][nx] == TOMB) {
                    continue;
                }

                if (dist[y][x] + 1 < dist[ny][nx]) {
                    dist[ny][nx] = dist[y][x] + 1;

                    if (!inq[ny][nx]) {
                        q.push({ny, nx});
                        inq[ny][nx] = true;
                        cnt[ny][nx] += 1;

                        if (cnt[ny][nx] >= w * h - g)  {
                            return false;
                        }
                    }
                }
            }
        }

        if (inq[h - 1][w - 1] && ans == -1) {
            ans = dist[h - 1][w - 1];
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> w >> h;

        if (w + h == 0) {
            break;
        }

        fill_n(&arr[0][0], 40 * 40, NONE);
        fill_n(&ghost[0][0], 40 * 40, vi());

        cin >> g;

        for (int i = 0; i < g; i++) {
            int x, y;

            cin >> x >> y;

            arr[y][x] = TOMB;
        }

        cin >> e;

        for (int i = 0; i < e; i++) {
            int x1, y1, x2, y2, t;

            cin >> x1 >> y1 >> x2 >> y2 >> t;

            arr[y1][x1] = GHOST;
            ghost[y1][x1] = {t, y2, x2};
        }

        //
        //
        //

        bool no_cycle = spfa();

        if (!no_cycle) {
            cout << "Never" << '\n';
        } else if (dist[h - 1][w - 1] == INF) {
            cout << "Impossible" << '\n';
        } else {
            cout << dist[h - 1][w - 1] << '\n';
        }
    }
}