#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int h, w;
char arr[110][110];
bool vis[110][110];
string init_key;
bool key[127];
vector<pii> door_pos[127];
vector<pii> start;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char upper_case(char c) {
    return c - 'a' + 'A';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    while (tc--) {
        fill_n(&arr[0][0], 110 * 110, '*');
        fill_n(key, 127, false);
        fill_n(door_pos, 127, vector<pii>());
        start.clear();

        cin >> h >> w;

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> arr[i][j];
            }
        }

        cin >> init_key;

        for (char k : init_key) {
            if (k == '0') {
                break;
            }

            key[upper_case(k)] = true;
        }

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (i == 1 || i == h || j == 1 || j == w) {
                    if (arr[i][j] == '*') {
                        continue;
                    }

                    if ('A' <= arr[i][j] && arr[i][j] <= 'Z') {
                        door_pos[arr[i][j]].push_back({i, j});

                        if (!key[arr[i][j]]) {
                            continue;
                        }
                    }

                    start.push_back({i, j});
                }
            }
        }

        //
        //
        //

        queue<pii> q;

        while (true) {
            bool add_key = false;

            fill_n(&vis[0][0], 110 * 110, false);

            for (auto pos : start) {
                vis[pos.first][pos.second] = true;
                q.push(pos);
            }

            while (!q.empty()) {
                int y, x;

                tie(y, x) = q.front();
                q.pop();

                if ('a' <= arr[y][x] && arr[y][x] <= 'z') {
                    int c = upper_case(arr[y][x]);

                    if (!key[c]) {
                        add_key = true;
                        key[c] = true;

                        for (auto pos : door_pos[c]) {
                            if (pos.first == 1 || pos.first == h || pos.second == 1 || pos.second == w) {
                                start.push_back(pos);
                            }
                        }
                    }
                }

                for (int *d : dir) {
                    int dy = y + d[0];
                    int dx = x + d[1];

                    if (arr[dy][dx] == '*') {
                        continue;
                    }

                    if (vis[dy][dx]) {
                        continue;
                    }

                    if ('A' <= arr[dy][dx] && arr[dy][dx] <= 'Z' && !key[arr[dy][dx]]) {
                        continue;
                    }

                    vis[dy][dx] = true;
                    q.push({dy, dx});
                }
            }

            if (!add_key) {
                break;
            }
        }

        //
        //
        //

        int ans = 0;

        fill_n(&vis[0][0], 110 * 110, false);

        for (auto pos : start) {
            vis[pos.first][pos.second] = true;
            q.push(pos);
        }

        while (!q.empty()) {
            int y, x;

            tie(y, x) = q.front();
            q.pop();

            if (arr[y][x] == '$') {
                ans += 1;
            }

            for (int *d : dir) {
                int dy = y + d[0];
                int dx = x + d[1];

                if (arr[dy][dx] == '*') {
                    continue;
                }

                if (vis[dy][dx]) {
                    continue;
                }

                if ('A' <= arr[dy][dx] && arr[dy][dx] <= 'Z' && !key[arr[dy][dx]]) {
                    continue;
                }

                vis[dy][dx] = true;
                q.push({dy, dx});
            }
        }

        cout << ans << '\n';
    }
}