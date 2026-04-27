#include <iostream>

#define pii pair<int, int>
#define R first
#define C second

using namespace std;

int n, m, d, ans;
pii pos;
int arr[55][55];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool move() {
    int r = pos.R;
    int c = pos.C;

    if (arr[r][c] == 0) {
        arr[r][c] = 2;
        ans++;
    }

    bool empty = false;
    for (int* dr : dir) {
        int nr = r + dr[0];
        int nc = c + dr[1];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            continue;

        if (arr[nr][nc] == 0)
            empty = true;
    }

    if (!empty) {
        int nr = r + dir[d][0] * -1;
        int nc = c + dir[d][1] * -1;

        if (arr[nr][nc] == 1)
            return false;

        pos = {nr, nc};

        return true;
    }

    d = (d == 0 ? 3 : d - 1);

    int nr = r + dir[d][0];
    int nc = c + dir[d][1];

    if (arr[nr][nc] == 0) {
        pos = {nr, nc};
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> pos.R >> pos.C >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    while (move());

    cout << ans;
}