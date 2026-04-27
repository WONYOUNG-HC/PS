#include <iostream>
#include <algorithm>

using namespace std;

int n, m, t;
int arr[300][300];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fill_n(&arr[0][0], 300 * 300, 1e9);
    for (int i = 1; i <= n; i++)
        arr[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;

        arr[u][v] = 0;
        arr[v][u] = (b ? 0 : 1);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    cin >> t;
    for (int i = 0; i < t; i++) {
        int s, e;
        cin >> s >> e;
        cout << arr[s][e] << '\n';
    }
}