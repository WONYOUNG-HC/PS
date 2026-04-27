#include <iostream>

using namespace std;

int n;
int arr[510][510];
int vis[510][510];
int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int tonado[4][5][5] = {{{0, 0, 2, 0, 0}, {0, 10, 7, 1, 0}, {5, 0, 0, 0, 0}, {0, 10, 7, 1, 0}, {0, 0, 2, 0, 0}}, };

int f(int y, int x, int d) {
    if (y == 1 && x == 1) {
        return 0;
    }

    vis[y][x] = true;

    //
    //
    //

    int nd = (d + 1) % 4;
    int ny = y + dir[nd][0];
    int nx = x + dir[nd][1];

    if ((y == n / 2 + 1 && x == n / 2 + 1) || vis[ny][nx]) {
        nd = d;
        ny = y + dir[nd][0];
        nx = x + dir[nd][1];
    }

    //
    //
    //

    int ret = 0;
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int dy = ny - 2 + i;
            int dx = nx - 2 + j;
            int sand = arr[ny][nx] * tonado[nd][i][j] / 100;

            if (dy < 1 || dy > n || dx < 1 || dx > n) {
                ret += sand;
            } else {
                arr[dy][dx] += sand;
            }

            sum += sand;
        }
    }

    int dy = ny + dir[nd][0];
    int dx = nx + dir[nd][1];

    if (dy < 1 || dy > n || dx < 1 || dx > n) {
        ret += arr[ny][nx] - sum;
    } else {
        arr[dy][dx] += arr[ny][nx] - sum;
    }

    arr[ny][nx] = 0;

    return ret + f(ny, nx, nd);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int k = 1; k < 4; k++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                tonado[k][4 - j][i] = tonado[k - 1][i][j];
            }
        }
    }

    cout << f(n / 2 + 1, n / 2 + 1, 0);
}