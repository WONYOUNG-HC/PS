#include <iostream>
#include <queue>

#define pii pair<int, int>
#define Y first
#define X second

using namespace std;

int r, c;
char arr[1010][1010];
queue<pii> q1, q2;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'J')
                q1.emplace(i, j);
            else if (arr[i][j] == 'F')
                q2.emplace(i, j);
        }
    }

    int time = 1;
    while (!q1.empty()) {
        queue<pii> _q;
        while (!q1.empty()) {
            pii cur = q1.front();
            q1.pop();

            if (arr[cur.Y][cur.X] == 'F')
                continue;

            if (cur.Y == 1 || cur.Y == r || cur.X == 1 || cur.X == c) {
                cout << time;
                return 0;
            }

            for (int* d : dir) {
                int dy = cur.Y + d[0];
                int dx = cur.X + d[1];

                if (arr[dy][dx] == '.') {
                    arr[dy][dx] = 'J';
                    _q.emplace(dy, dx);
                }
            }
        }
        q1.swap(_q);

        while (!q2.empty()) {
            pii cur = q2.front();
            q2.pop();

            for (int* d : dir) {
                int dy = cur.Y + d[0];
                int dx = cur.X + d[1];

                if (arr[dy][dx] == '.' || arr[dy][dx] == 'J') {
                    arr[dy][dx] = 'F';
                    _q.emplace(dy, dx);
                }
            }
        }
        q2.swap(_q);

        time++;
    }

    cout << "IMPOSSIBLE";
}