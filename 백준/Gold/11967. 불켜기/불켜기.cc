#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int, int>
#define Y first
#define X second

using namespace std;

int n, m;
bool light[110][110], vis[110][110];
vector<pii> sw[110][110];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        sw[y][x].emplace_back(b, a);
    }

    queue<pii> q;
    q.emplace(1, 1);
    light[1][1] = true;
    vis[1][1] = true;

    int ans = 1;
    while (!q.empty()) {
        int y = q.front().Y;
        int x = q.front().X;
        q.pop();

        for (pii& pr : sw[y][x]) {
            if (light[pr.Y][pr.X])
                continue;

            light[pr.Y][pr.X] = true;
            ans++;
            for (int *d : dir) {
                int dy = pr.Y + d[0];
                int dx = pr.X + d[1];

                if (vis[dy][dx]) {
                    q.emplace(pr.Y, pr.X);
                    vis[pr.Y][pr.X] = true;
                    break;
                }
            }
        }

        for (int *d : dir) {
            int dy = y + d[0];
            int dx = x + d[1];

            if (dy < 1 || dy > n || dx < 1 || dx > n)
                continue;
            if (!light[dy][dx] || vis[dy][dx])
                continue;

            q.emplace(dy, dx);
            vis[dy][dx] = true;
        }
    }

    cout << ans;
}
