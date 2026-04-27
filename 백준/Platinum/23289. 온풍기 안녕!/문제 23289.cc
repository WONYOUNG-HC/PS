#include <iostream>
#include <vector>

using namespace std;

struct Pos {
    int y, x;
};

struct Heater: Pos {
    int d;
};

int r, c, k;
int arr[22][22];
vector<Heater> heaters;
vector<Pos> chks;
int w;
bool wall[22][22][22][22];

bool in_arr(int y, int x) {
    return 0 < y && y < r + 1 && 0 < x && x < c + 1;
}

bool can_prop(int sy, int sx, int ty, int tx, int hd) {
    if ((sy == ty || sx == tx) && !wall[sy][sx][ty][tx]) {
        return true;
    }

    int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<Pos> v;

    for (int i = 1; i <= 4; i++) {
        if (i == hd) {
            continue;
        }

        int dy = sy + dir[i][0];
        int dx = sx + dir[i][1];

        if (!in_arr(dy, dx)) {
            continue;
        }

        if (wall[sy][sx][dy][dx]) {
            continue;
        }

        v.push_back({dy, dx});
    }

    for (auto p : v) {
        for (int i = 1; i <= 4; i++) {
            int dy = p.y + dir[i][0];
            int dx = p.x + dir[i][1];

            if (!in_arr(dy, dx)) {
                continue;
            }

            if (wall[p.y][p.x][dy][dx]) {
                continue;
            }

            if (dy == ty && dx == tx) {
                return true;
            }
        }
    }

    return false;
}

void heat(Heater h) {
    bool vis[22][22] = {};
    int dir[5][2] = {{0, 0}, {-1, 1}, {-1, -1}, {-1, -1}, {1, -1}};

    int y = h.y + dir[h.d][0];
    int x = h.x + dir[h.d][1];

    if (h.d < 3) {
        y += 1;
    } else {
        x += 1;
    }

    if (!in_arr(y, x)) {
        return;
    }

    if (wall[h.y][h.x][y][x]) {
        return;
    }

    vis[y][x] = true;
    arr[y][x] += 5;

    for (int i = 1; i < 5; i++) {
        y = h.y + dir[h.d][0] * i;
        x = h.x + dir[h.d][1] * i;

        for (int j = 1; j <= i * 2 - 1; j++) {
            if (h.d < 3) {
                y += 1;
            } else {
                x += 1;
            }

            if (!in_arr(y, x)) {
                continue;
            }

            if (!vis[y][x]) {
                continue;
            }

            for (int c = 0; c < 3; c++) {
                int dy = y + dir[h.d][0];
                int dx = x + dir[h.d][1];

                if (h.d < 3) {
                    dy += c;
                } else {
                    dx += c;
                }

                if (!in_arr(dy, dx)) {
                    continue;
                }

                if (vis[dy][dx]) {
                    continue;
                }

                if (can_prop(y, x, dy, dx, h.d)) {
                    vis[dy][dx] = true;
                    arr[dy][dx] += 5 - i;
                }
            }
        }
    }
}

void mix() {
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int lazy[22][22] = {};

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            for (int *d : dir) {
                int dy = i + d[0];
                int dx = j + d[1];

                if (!in_arr(dy, dx)) {
                    continue;
                }

                if (wall[i][j][dy][dx]) {
                    continue;
                }

                if (arr[i][j] < arr[dy][dx]) {
                    continue;
                }

                int diff = (arr[i][j] - arr[dy][dx]) / 4;
                lazy[i][j] -= diff;
                lazy[dy][dx] += diff;
            }
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            arr[i][j] += lazy[i][j];
        }
    }
}

void decrease() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (i == 1 || i == r) {
                arr[i][j] = max(0, arr[i][j] - 1);
            } else if (j == 1 || j == c) {
                arr[i][j] = max(0, arr[i][j] - 1);
            }
        }
    }
}

bool stop() {
    for (auto pos : chks) {
        if (arr[pos.y][pos.x] < k) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> k;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int a;

            cin >> a;

            if (0 < a && a < 5) {
                Heater h;

                h.y = i;
                h.x = j;
                h.d = a;

                heaters.push_back(h);
            } else if (a == 5) {
                Pos p;

                p.y = i;
                p.x = j;

                chks.push_back(p);
            }
        }
    }

    cin >> w;

    for (int i = 0; i < w; i++) {
        int y, x, t;

        cin >> y >> x >> t;

        if (t == 0) {
            wall[y][x][y - 1][x] = true;
            wall[y - 1][x][y][x] = true;
        } else if (t == 1) {
            wall[y][x][y][x + 1] = true;
            wall[y][x + 1][y][x] = true;
        }
    }

    for (int q = 1; q <= 100; q++) {
        for (auto heater : heaters) {
            heat(heater);
        }

        mix();   
        
        decrease();

        if (stop()) {
            cout << q;

            return 0;
        }
    }

    cout << 101;
}