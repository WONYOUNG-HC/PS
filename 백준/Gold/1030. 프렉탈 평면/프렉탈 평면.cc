#include <iostream>

using namespace std;

int s, n, k, r1, r2, c1, c2;

int f(int y, int x, int m) {
    if (m == -1) {
        return 0;
    }

    int step = 1;

    for (int i = 0; i < m; i++) {
        step *= n;
    }

    int dist = step * (n - k) / 2;

    if (dist <= y && y < step * n - dist && dist <= x && x < step * n - dist) {
        return 1;
    }

    return f(y % step, x % step, m - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            cout << f(i, j, s - 1);
        } 
        cout << '\n';
    }
}