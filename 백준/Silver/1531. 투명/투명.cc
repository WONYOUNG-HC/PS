#include <iostream>

using namespace std;

int n, m;
int arr[110][110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = y1; j <= y2; j++)
            for (int k = x1; k <= x2; k++)
                arr[j][k]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            arr[i][j] > m && ans++;

    cout << ans;
}