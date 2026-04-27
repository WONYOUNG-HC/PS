#include <iostream>
#include <algorithm>

#define INF 100
#define pii pair<int, int>
#define Y first
#define X second

using namespace std;

int n, m, ans = INF;
char graph[15][15];
bool vis[15][15][15][15];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void move(pii r, pii& nr, pii b, pii& nb, int* d) {
    nr = {r.Y + d[0], r.X + d[1]};
    if (graph[nr.Y][nr.X] == '#' || graph[r.Y][r.X] == 'O')
        nr = r;

    nb = {b.Y + d[0], b.X + d[1]};
    if (graph[nb.Y][nb.X] == '#' || graph[b.Y][b.X] == 'O')
        nb = b;

    if (r == nr && b == nb)
        return;

    if (nr == r && nb == nr) {
        if (graph[nr.Y][nr.X] != 'O')
            nb = b;
        return;
    }

    if (nb == b && nr == nb) {
        if (graph[nb.Y][nb.X] != 'O')
            nr = r;
        return;
    }

    move(nr, nr, nb, nb, d);
}

void dfs(pii r, pii b, int cur) {
    if (cur > 10)
        return;

    for (int* d : dir) {
        pii nr, nb;
        move(r, nr, b, nb, d);

        if (graph[nb.Y][nb.X] == 'O')
            continue;

        if (graph[nr.Y][nr.X] == 'O') {
            ans = min(ans, cur + 1);
            continue;
        }

        if (vis[nr.Y][nr.X][nb.Y][nb.X])
            continue;

        vis[nr.Y][nr.X][nb.Y][nb.X] = true;
        dfs(nr, nb, cur + 1);
        vis[nr.Y][nr.X][nb.Y][nb.X] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    pii r, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 'R')
                r = {i, j}, graph[i][j] = '.';
            else if (graph[i][j] == 'B')
                b = {i, j}, graph[i][j] = '.';
        }
    }

    vis[r.Y][r.X][b.Y][b.X] = true;

    dfs(r, b, 0);

    cout << (ans > 10 ? -1 : ans);
}