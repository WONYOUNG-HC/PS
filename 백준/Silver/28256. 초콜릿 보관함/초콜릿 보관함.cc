#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[3][3];
int a[4];
int n;
bool vis[3][3];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.emplace(y, x);
    vis[y][x] = true;

    int con = 1;
    while (!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();

        for (int* d : dir) {
            int dy = ny + d[0];
            int dx = nx + d[1];

            if (dy < 0 || dy > 2 || dx < 0 || dx > 2)
                continue;

            if (board[dy][dx] == 'O' && !vis[dy][dx]) {
                q.emplace(dy, dx);
                vis[dy][dx] = true;
                con++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == con) {
            a[i] = -1;
            return true;
        }
    }

    return false;
}

bool solve() {
    for (auto& s : board)
        cin >> s;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(vis, 0, sizeof(vis));

    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O' && !vis[i][j]) {
                cnt++;
                if (!bfs(i, j))
                    return false;
            }
        }
    }

    if (cnt != n)
        return false;

    for (int i = 0; i < n; i++)
        if (a[i] != -1)
            return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--)
        cout << (solve() ? 1 : 0) << '\n';
}