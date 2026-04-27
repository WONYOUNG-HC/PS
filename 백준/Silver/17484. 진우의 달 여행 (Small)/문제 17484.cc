#include <iostream>

using namespace std;

int n, m;
int arr[10][10];
int ans = 1e9;

void f(int y, int x, int sum, int dir) {
    if (y > n) {
        ans = min(ans, sum);

        return;
    }

    if (x < 1 || x > m) {
        return;
    }

    sum += arr[y][x];

    for (int i = -1; i <= 1; i++) {
        if (i != dir) {
            f(y + 1, x + i, sum, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        f(1, i, 0, 2);
    }

    cout << ans;
}