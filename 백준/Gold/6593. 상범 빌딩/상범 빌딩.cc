#include <iostream>
#include <queue>
#include <tuple>

#define Z(tp) get<0>(tp)
#define Y(tp) get<1>(tp)
#define X(tp) get<2>(tp)
#define T(tp) get<3>(tp)

using namespace std;

int l, r, c;
char arr[33][33][33];
bool vis[33][33][33];
int dir[6][3] = {{-1, 0, 0}, {1, 0, 0},
                 {0, -1, 0}, {0, 1, 0},
                 {0, 0, -1}, {0, 0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> l >> r >> c;

        if (l == 0)
            break;

        tuple<int, int, int> pos;
        for (int i = 1; i <= l; i++)
            for (int j = 1; j <= r; j++)
                for (int k = 1; k <= c; k++) {
                    cin >> arr[i][j][k];
                    vis[i][j][k] = false;
                    if (arr[i][j][k] == 'S')
                        pos = {i, j, k};
                }

        int ans = 0;
        queue<tuple<int, int, int, int>> q;
        q.emplace(Z(pos), Y(pos), X(pos), 0);
        vis[Z(pos)][Y(pos)][X(pos)] = true;

        bool flag = false;
        while (!q.empty()) {
            int z = Z(q.front());
            int y = Y(q.front());
            int x = X(q.front());
            int t = T(q.front());
            q.pop();

            if (arr[z][y][x] == 'E') {
                cout << "Escaped in " << t << " minute(s).\n";
                flag = true;
                break;
            }

            for (int* d : dir) {
                int dz = z + d[0];
                int dy = y + d[1];
                int dx = x + d[2];

                if (dz < 1 || dz > l || dy < 1 || dy > r || dx < 1 || dx > c)
                    continue;

                if (arr[dz][dy][dx] == '#')
                    continue;

                if (!vis[dz][dy][dx]) {
                    vis[dz][dy][dx] = true;
                    q.emplace(dz, dy, dx, t + 1);
                }
            }
        }

        if (!flag) cout << "Trapped!\n";
    }
}