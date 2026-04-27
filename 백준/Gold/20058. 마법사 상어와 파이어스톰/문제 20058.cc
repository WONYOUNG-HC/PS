#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, q;
int arr[100][100];
int l[1010];
int pow2[100];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void rotate_arr(int r1, int c1, int r2, int c2) {
    int temp[100][100];

    for (int i = r1; i < r2; i++) {
        for (int j = c1; j < c2; j++) {
            temp[i - r1][j - c1] = arr[i][j];
        }
    }

    for (int i = 0; i < (r2 - r1); i++) {
        for (int j = 0; j < (c2 - c1); j++) {
            arr[r1 + j][c1 + (c2 - c1) - 1 - i] = temp[i][j];
        }
    }
}

void decrease() {
    bool dec[100][100] = {};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;

            for (int *d : dir) {
                int dy = i + d[0];
                int dx = j + d[1];

                if (dy == -1 || dy == n || dx == -1 || dx == n) {
                    continue;
                }

                if (arr[dy][dx] > 0) {
                    cnt += 1;
                }
            }

            if (cnt <= 2) {
                dec[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dec[i][j] && arr[i][j] > 0) {
                arr[i][j] -= 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pow2[0] = 1;
    for (int i = 1; i < 100; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }

    cin >> n >> q;

    n = pow2[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> l[i];
    }

    //
    //
    //

    for (int t = 0; t < q; t++) {
        int step = pow2[l[t]];

        for (int i = 0; i < n; i += step) {
            for (int j = 0; j < n; j += step) {
                rotate_arr(i, j, i + step, j + step);
            }
        }

        decrease();
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
    }

    cout << sum << '\n';

    //
    //
    //

    bool vis[100][100] = {};
    queue<pii> q;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && arr[i][j] > 0) {
                int cnt = 1;
                vis[i][j] = true;
                q.push({i, j});

                while (!q.empty()) {
                    pii cur = q.front();
                    q.pop();

                    for (int *d : dir) {
                        int dy = cur.first + d[0];
                        int dx = cur.second + d[1];

                        if (dy == -1 || dy == n || dx == -1 || dx == n) {
                            continue;
                        }

                        if (vis[dy][dx]) {
                            continue;
                        }

                        if (arr[dy][dx] == 0) {
                            continue;
                        }

                        cnt += 1;
                        vis[dy][dx] = true;
                        q.push({dy, dx});
                    }
                }

                ans = max(ans, cnt);
            }
        }
    }
    
    cout << ans;
}