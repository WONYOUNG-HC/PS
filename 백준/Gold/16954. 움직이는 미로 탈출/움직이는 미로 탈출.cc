#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
    int cnt, y, x;

    pos(int _cnt, int _y, int _x) {
        cnt = _cnt;
        y = _y;
        x = _x;
    }
};

char arr[100][10][10];
bool vis[100][10][10];
int dir[9][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0, 0}};

int main() {
    fill_n(**arr, 10 * 10 * 10, '#');
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> arr[0][i][j];
        }
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 2; j <= 8; j++) {
            for (int k = 1; k <= 8; k++) {
                arr[i][j][k] = arr[i - 1][j - 1][k];
            }
        }

        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= 8; k++) {
                arr[i][j][k] = '.';
            }
        }
    }

    for (int i = 9; i <= 100; i++) {
        for (int j = 1; j <= 8; j++) {
            for (int k = 1; k <= 8; k++) {
                arr[i][j][k] = '.';
            }
        }
    }

    queue<pos> q;
    q.emplace(0, 8, 1);
    vis[0][8][1] = true;

    while (!q.empty()) {
        int cnt = q.front().cnt;
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        if (y == 1 && x == 8) {
            cout << 1;

            return 0;
        }

        for (int *d : dir) {
            int dy = y + d[0];
            int dx = x + d[1];

            if (!vis[cnt + 1][dy][dx] && arr[cnt][dy][dx] == '.' && arr[cnt + 1][dy][dx] == '.') {
                q.emplace(cnt + 1, dy, dx);
                vis[cnt + 1][dy][dx] = true;
            }
        }
    }

    cout << 0;
}