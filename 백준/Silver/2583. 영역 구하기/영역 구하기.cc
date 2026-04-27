#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m, n, k;
vector<vector<bool>> wall, vis;
vector<int> space;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.emplace(y, x);
    vis[y][x] = true;
    int ret = 1;

    while (!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();

        for (int* dir : direction) {
            int dy = ny + dir[0];
            int dx = nx + dir[1];

            if (dy < 0 || dy >= m || dx < 0 || dx >= n)
                continue;
            if (vis[dy][dx] || wall[dy][dx])
                continue;

            ret++;
            vis[dy][dx] = true;
            q.emplace(dy, dx);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> k;

    wall.resize(m, vector<bool>(n));
    vis.resize(m, vector<bool>(n));

    for (int i = 0; i < k ; i++) {
        int lbx, lby, rtx, rty;
        cin >> lbx >> lby >> rtx >> rty;

        for (int y = lby; y < rty; y++) {
            for (int x = lbx; x < rtx; x++) {
                wall[y][x] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && !wall[i][j]) {
                space.push_back(BFS(i, j));
            }
        }
    }

    sort(space.begin(), space.end());

    cout << space.size() << '\n';
    for (int x : space)
        cout << x << ' ';
}