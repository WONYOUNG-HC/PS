#include <iostream>
#include <algorithm>

using namespace std;

int r, c, t;
int arr[60][60], narr[60][60];
pair<int, int> cleaner[2];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool expand(int y, int x, int d) {
    int ny = y + dir[d][0];
    int nx = x + dir[d][1];

    if (ny < 1 || ny > r || nx < 1 || nx > c || arr[ny][nx] == -1)
        return false;

    narr[ny][nx] += arr[y][x] / 5;

    return true;
}

void move(int k, int d) {
    int y = cleaner[k].first + dir[d][0];
    int x = cleaner[k].second;

    while (true) {
        int dy = y + dir[d][0];
        int dx = x + dir[d][1];

        if (arr[dy][dx] == -1)
            return;

        if (dy < 1 || dy > r || dx < 1 || dx > c || (dy == cleaner[!k].first && dx == c)) {
            for (int i = 0; i < 4; i++) {
                dy = y + dir[i][0];
                dx = x + dir[i][1];

                if (dy == y - dir[d][0] && dx == x - dir[d][1])
                    continue;

                if (1 <= dy && dy <= r && 1 <= dx && dx <= c && dy != cleaner[!k].first) {
                    d = i;
                    break;
                }
            }
        }

        arr[y][x] = arr[dy][dx];
        y = dy, x = dx;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> t;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == -1) {
                int k = cleaner[0].first == 0 ? 0 : 1;
                cleaner[k] = {i, j};
            }
        }
    }

    while (t--) {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (arr[i][j] > 0) {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        expand(i, j, k) && cnt++;
                    }

                    arr[i][j] -= arr[i][j] / 5 * cnt;
                }
            }
        }

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                arr[i][j] += narr[i][j];
        fill_n(&narr[0][0], 60 * 60, 0);


        move(0, 0);
        move(1, 1);

        arr[cleaner[0].first][cleaner[0].second + 1] = 0;
        arr[cleaner[1].first][cleaner[1].second + 1] = 0;

    }

    int ans = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            ans += (arr[i][j] > 0 ? arr[i][j] : 0);

    cout << ans;
}