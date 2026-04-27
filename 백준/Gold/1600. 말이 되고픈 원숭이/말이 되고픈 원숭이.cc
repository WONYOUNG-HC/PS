#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int k, w, h;
int arr[210][210];
bool vis[40][210][210];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int horse[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                   {1, 2}, {2, 1}, {2, -1}, {1, -2}};

int bfs() {
    queue<tuple<int, int, int, int>> q;
    q.emplace(0, 0, 1, 1);
    vis[0][1][1] = true;

    while (!q.empty()) {
        int cnt = get<0>(q.front());
        int hcnt = get<1>(q.front());
        int y = get<2>(q.front());
        int x = get<3>(q.front());
        q.pop();

        if (y == h && x == w)
            return cnt;

        for (int* d : dir) {
            int dy = d[0] + y;
            int dx = d[1] + x;

            if (dy < 1 || dy > h || dx < 1 || dx > w)
                continue;

            if (arr[dy][dx] == 1)
                continue;

            if (vis[hcnt][dy][dx])
                continue;

            vis[hcnt][dy][dx] = true;
            q.emplace(cnt + 1, hcnt, dy, dx);
        }

        if (hcnt == k)
            continue;

        for (int* hor : horse) {
            int hy = hor[0] + y;
            int hx = hor[1] + x;

            if (hy < 1 || hy > h || hx < 1 || hx > w)
                continue;

            if (arr[hy][hx] == 1)
                continue;

            if (vis[hcnt + 1][hy][hx])
                continue;

            vis[hcnt + 1][hy][hx] = true;
            q.emplace(cnt + 1, hcnt + 1, hy, hx);
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> w >> h;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> arr[i][j];

    cout << bfs();
}