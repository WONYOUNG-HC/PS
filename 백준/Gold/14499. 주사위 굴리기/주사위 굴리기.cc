#include <iostream>
#include <algorithm>

using namespace std;

enum {U, D, L, R, F, B};

int n, m, x, y, k;
int board[22][22];
int dice[6];
int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < k; i++) {
        int c; cin >> c;

        x += dir[c][0]; y += dir[c][1];
        if (x < 0 || x > n - 1 || y < 0 || y > m - 1) {
            x -= dir[c][0]; y -= dir[c][1];
            continue;
        }

        if (c == 1) {
            swap(dice[U], dice[R]);
            swap(dice[U], dice[D]);
            swap(dice[U], dice[L]);
        }
        else if (c == 2) {
            swap(dice[U], dice[L]);
            swap(dice[U], dice[D]);
            swap(dice[U], dice[R]);
        }
        else if (c == 3) {
            swap(dice[U], dice[B]);
            swap(dice[U], dice[D]);
            swap(dice[U], dice[F]);
        }
        else {
            swap(dice[U], dice[F]);
            swap(dice[U], dice[D]);
            swap(dice[U], dice[B]);
        }

        if (board[x][y] == 0) {
            board[x][y] = dice[D];
        }
        else {
            dice[D] = board[x][y];
            board[x][y] = 0;
        }

        cout << dice[U] << '\n';
    }
}