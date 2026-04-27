#include <iostream>

using namespace std;

int r, c;
char graph[10010][510];

int dir[3][2] = {{-1, 1}, {0, 1}, {1, 1}};

bool dfs(int y, int x) {
    if (x == c)
        return true;

    for (int* d : dir) {
        int dy = y + d[0];
        int dx = x + d[1];

        if (graph[dy][dx] == '.') {
            graph[dy][dx] = 'g';

            if (dfs(dy, dx))
                return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> graph[i][j];

    int ans = 0;
    for (int i = 1; i <= r; i++)
        if (dfs(i, 1)) ans++;

    cout << ans;
}