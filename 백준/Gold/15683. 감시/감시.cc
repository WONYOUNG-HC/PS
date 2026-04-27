#include <iostream>
#include <vector>
#include <algorithm>

#define vbb vector<vector<bool>>
#define pii pair<int, int>
#define R first
#define C second

using namespace std;

int n, m, ntv, ans;
int arr[10][10];
pii tv[8];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int cnt, int cur, vbb vis) {
    if (cnt == ntv) {
        ans = max(ans, cur);
        return;
    }

    pii p = tv[cnt];
    vbb nvis = vis;
    int ncur = cur;

    if (arr[p.R][p.C] == 5) {
        for (int *d: dir) {
            int dr = p.R + d[0];
            int dc = p.C + d[1];

            while (arr[dr][dc] != 6) {
                if (!vis[dr][dc] && arr[dr][dc] == 0)
                    ncur++;
                nvis[dr][dc] = true;

                dr += d[0], dc += d[1];
            }
        }

        dfs(cnt + 1, ncur, nvis);

        return;
    }

    for (int* d : dir) {
        int dr = p.R + d[0];
        int dc = p.C + d[1];

        nvis = vis, ncur = cur;

        while (arr[dr][dc] != 6) {
            if (!vis[dr][dc] && arr[dr][dc] == 0)
                ncur++;
            nvis[dr][dc] = true;

            dr += d[0], dc += d[1];
        }

        if (arr[p.R][p.C] == 1) {
            dfs(cnt + 1, ncur, nvis);
        }
        else if (arr[p.R][p.C] == 2) {
            int rr = p.R + d[0] * -1;
            int rc = p.C + d[1] * -1;

            while (arr[rr][rc] != 6) {
                if (!vis[rr][rc] && arr[rr][rc] == 0)
                    ncur++;
                nvis[rr][rc] = true;

                rr += d[0] * -1, rc += d[1] * -1;
            }

            dfs(cnt + 1, ncur, nvis);
        }
        else if (arr[p.R][p.C] == 3) {
            int nd[2] = {d[1],d[0] * -1};

            int nr = p.R + nd[0];
            int nc = p.C + nd[1];

            while (arr[nr][nc] != 6) {
                if (!vis[nr][nc] && arr[nr][nc] == 0)
                    ncur++;
                nvis[nr][nc] = true;

                nr += nd[0], nc += nd[1];
            }

            dfs(cnt + 1, ncur, nvis);
        }
        else if (arr[p.R][p.C] == 4) {
            for (int* nd : dir) {
                if ((nd[0] == d[0] && nd[1] == d[1]) ||
                        (nd[0] == d[0] * -1 && nd[1] == d[1] * -1))
                    continue;

                int nr = p.R + nd[0];
                int nc = p.C + nd[1];

                while (arr[nr][nc] != 6) {
                    if (!vis[nr][nc] && arr[nr][nc] == 0)
                        ncur++;
                    nvis[nr][nc] = true;

                    nr += nd[0], nc += nd[1];
                }
            }

            dfs(cnt + 1, ncur, nvis);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int non = 0;
    fill_n(&arr[0][0], 100, 6);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];

            if (1 <= arr[i][j] && arr[i][j] <= 5)
                tv[ntv++] = {i, j};

            arr[i][j] != 0 && non++;
        }
    }

    vbb vis(10, vector<bool>(10));
    dfs(0, 0, vis);

    cout << n * m - non - ans;
}