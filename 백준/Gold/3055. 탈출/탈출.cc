#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int r, c;
char arr[60][60];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    queue<pii> qs, _qs, qw, _qw;
    fill_n(&arr[0][0], 60 * 60, 'X');
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'S') qs.emplace(i, j);
            else if (arr[i][j] == '*') qw.emplace(i, j);
        }
    }

    int ans = 1;
    while (!qs.empty()) {
        while (!qs.empty()) {
            int y = qs.front().first;
            int x = qs.front().second;
            qs.pop();

            if (arr[y][x] == '*')
                continue;

            for (int *d : dir) {
                int dy = y + d[0];
                int dx = x + d[1];

                if (arr[dy][dx] == 'D') {
                    cout << ans;
                    return 0;
                }

                if (arr[dy][dx] == '.') {
                    arr[dy][dx] = 'S';
                    _qs.emplace(dy, dx);
                }
            }
        }

        while (!qw.empty()) {
            int y = qw.front().first;
            int x = qw.front().second;
            qw.pop();
            
            for (int *d : dir) {
                int dy = y + d[0];
                int dx = x + d[1];

                if (arr[dy][dx] == '.' || arr[dy][dx] == 'S') {
                    arr[dy][dx] = '*';
                    _qw.emplace(dy, dx);
                }
            }
        }

        qs.swap(_qs);
        qw.swap(_qw);
        ans++;
    }

    cout << "KAKTUS";
}