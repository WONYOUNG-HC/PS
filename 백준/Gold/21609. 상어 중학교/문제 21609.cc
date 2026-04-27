#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

const int RAINBOW = 0;
const int BLACK = -1;
const int BLANK = -2;

int n, m;
int arr[30][30];
int vis[30][30];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pii dfs1(int y, int x, int num) {
    pii ret = {1, 0};

    if (arr[y][x] == RAINBOW) {
        ret.second = 1;
    }

    vis[y][x] = true;

    for (int *d : dir) {
        int dy = y + d[0];
        int dx = x + d[1];

        if ((arr[dy][dx] == RAINBOW || arr[dy][dx] == num) && !vis[dy][dx]) {
            pii res = dfs1(dy, dx, num);

            ret.first += res.first;
            ret.second += res.second;
        }
    }

    return ret;
}

void dfs2(int y, int x, int num) {
    arr[y][x] = BLANK;
    vis[y][x] = true;

    for (int *d : dir) {
        int dy = y + d[0];
        int dx = x + d[1];

        if (arr[dy][dx] == RAINBOW || arr[dy][dx] == num) {
            dfs2(dy, dx, num);
        }
    }
}

void gravity() {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            int row = n - i + 1;

            while (arr[row][j] == BLANK) {
                row -= 1;
            }

            if (arr[row][j] == BLACK) {
                continue;
            }

            swap(arr[row][j], arr[n - i + 1][j]);
        }
    }
}

void rotate() {
    int temp[30][30] = {};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            temp[n - j + 1][i] = arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fill_n(&arr[0][0], 30 * 30, BLACK);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    //
    //
    //

    int ans = 0;

    while (true) {
        pii size;
        pii standard;

        fill_n(&vis[0][0], 30 * 30, false);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] > 0 && !vis[i][j]) {
                    pii res = dfs1(i, j, arr[i][j]);

                    if (res.first > size.first || (res.first == size.first && res.second >= size.second)) {
                        size = res;
                        standard = {i, j};
                    }

                    for (int ii = 1; ii <= n; ii++) {
                        for (int jj = 1; jj <= n; jj++) {
                            if (arr[ii][jj] == RAINBOW) {
                                vis[ii][jj] = false;
                            }
                        }
                    }
                }
            }
        }

        if (size.first < 2) {
            break;
        }

        //
        //
        //

        dfs2(standard.first, standard.second, arr[standard.first][standard.second]);

        ans += size.first * size.first;

        //
        //
        //

        gravity();

        rotate();
        
        gravity();
    }

    cout << ans;
}