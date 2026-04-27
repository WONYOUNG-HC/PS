#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[55][55];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    fill_n(&arr[0][0], 55 * 55, 1e9);
    for (int i = 1; i <= n; i++) arr[i][i] = 0;

    while (true) {
        int a, b;
        cin >> a >> b;

        if (a + b == -2)
            break;

        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    int cnt = 0, mn = 1e9;
    for (int i = 1; i <= n; i++) {
        int sc = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;

            sc = max(sc, arr[i][j]);
        }

        if (sc < mn)
            mn = sc, cnt = 1;
        else if (sc == mn)
            cnt++;
    }

    cout << mn << ' ' << cnt << '\n';

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j <= n; j++)
            (arr[i][j] > mn) && (flag = false);
        flag && (cout << i << ' ');
    }
}