#include <iostream>

using namespace std;

int n, m, h, ans = 5;

bool arr[50][50];

bool isEnd() {
    for (int i = 1; i <= n; i++) {
        int pos = i;
        for (int j = 1; j <= h; j++) {
            if (arr[j][pos])
                pos++;
            else if (arr[j][pos - 1])
                pos--;
        }

        if (pos != i)
            return false;
    }

    return true;
}

void recur(int cnt, int r, int c) {
    if (isEnd()) {
        ans = min(ans, cnt);
        return;
    }

    if (cnt == 3)
        return;

    for (int i = r; i <= n; i++) {
        for (int j = 1; j <= h; j++) {
            if (i == r && j < c)
                continue;

            if (!arr[j][i - 1] && !arr[j][i] && !arr[j][i + 1]) {
                arr[j][i] = true;
                recur(cnt + 1, i, j + 1);
                arr[j][i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
    }

    recur(0, 1, 1);

    cout << (ans == 5 ? -1 : ans);
}