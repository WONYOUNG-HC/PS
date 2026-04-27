#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Pos {
    int y, x;
};

int n, k;
int arr[110][110];
Pos start;
Pos end_up;
Pos end_down;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void init_pos() {
    start.x = 0;
    start.y = 0;
    end_up.x = 0;
    end_up.y = 0;
    end_down.x = n - 1;
    end_down.y = 0;
}

bool chk() {
    int mx = -1e9;
    int mn = 1e9;

    for (int j = 0; j < n; j++) {
        mx = max(mx, arr[0][j]);
        mn = min(mn, arr[0][j]);
    }

    return mx - mn <= k;
}

void fill_aqua() {
    int mn = *min_element(arr[0], arr[0] + n);
    
    for (int i = 0; i < n; i++) {
        if (arr[0][i] == mn) {
            arr[0][i] += 1;
        }
    }
}

void up_left() {
    arr[1][1] = arr[0][0];

    start.x = 1;
    end_up.y = 1;
    end_up.x = 1;
}

void rotate90(int a[110][110], int r, int c) {
    int tmp[110][110] = {0, };

    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            tmp[c - j][i] = a[i][j];
        }
    }

    for (int i = 0; i <= c; i++) {
        for (int j = 0; j <= r; j++) {
            a[i][j] = tmp[i][j];
        }
    }
}

void upup() {
    int r = end_up.y - start.y;
    int c = end_up.x - start.x;
    int tmp[110][110] = {0, };

    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            tmp[i][j] = arr[i][start.x + j];
        }
    }
    
    start.x += c + 1;
    end_up.y = c + 1;
    end_up.x = start.x + r;

    rotate90(tmp, r, c);
    swap(r, c);

    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            arr[1 + i][start.x + j] = tmp[i][j];
        }
    }
}

void propa() {
    int diff[110][110] = {0, };

    for (int i = 1; i <= end_up.y; i++) {
        for (int j = start.x; j <= end_up.x; j++) {
            for (int *d : dir) {
                int dy = i + d[0];
                int dx = j + d[1];

                if (dy < 0 || dy > end_up.y || dx < start.x || dx > end_up.x) {
                    continue;
                }

                if (arr[i][j] > arr[dy][dx]) {
                    continue;
                }
                
                int div = (arr[dy][dx] - arr[i][j]) / 5;

                diff[i][j] += div;
                diff[dy][dx] -= div;
            }
        }
    }

    for (int j = start.x; j <= end_down.x; j++) {
        for (int *d : dir) {
            int dy = 0 + d[0];
            int dx = j + d[1];

            if (dx < start.x || dx > end_down.x) {
                continue;
            }

            if (dy == -1 || (dy == 1 && end_up.y < 1)) {
                continue;
            }

            if (j > end_up.x && dy != 0) {
                continue;
            }

            if (arr[0][j] > arr[dy][dx]) {
                continue;
            }

            int div = (arr[dy][dx] - arr[0][j]) / 5;

            diff[0][j] += div;
            diff[dy][dx] -= div;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] += diff[i][j];
        }
    }
}

void spread() {
    int tmp[110][110] = {0, };
    int idx = 0;

    for (int j = start.x; j <= end_up.x; j++) {
        for (int i = 0; i <= end_up.y; i++) {
            tmp[0][idx] = arr[i][j];
            idx += 1;
        }
    }

    for (int j = end_up.x + 1; j <= end_down.x; j++) {
        tmp[0][idx] = arr[0][j];
        idx += 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = tmp[i][j];
        }
    }

    init_pos();
}

void fold() {
    int tmp[110][110] = {0, };
    int r = end_up.y;
    int c = (end_down.x - start.x) / 2;

    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            tmp[i][j] = arr[start.y + i][start.x + j];
        }
    }

    rotate90(tmp, r, c);
    rotate90(tmp, c, r);

    start.x += c + 1;

    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            arr[end_up.y + 1 + i][start.x + j] = tmp[i][j];
        }
    }

    end_up.y = (r + 1) * 2 - 1;
    end_up.x = end_down.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[0][i];
    }

    //
    //
    //

    int ans = 0;

    while (true) {
        if (chk()) {
            break;
        }

        init_pos();
        fill_aqua();
        up_left();

        while (end_up.y < end_down.x - end_up.x) {
            upup();
        }

        propa();
        spread();

        fold();
        fold();

        propa();
        spread();

        ans += 1;
    }

    cout << ans;
}