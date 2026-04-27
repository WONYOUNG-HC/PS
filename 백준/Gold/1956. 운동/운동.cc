#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int v, e;
int arr[410][410];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e;

    fill_n(&arr[0][0], 410 * 410, INF);
    for (int i = 1; i <= v; i++)
        arr[i][i] = 0;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

    int ans = INF;
    for (int i = 1; i <= v; i++)
        for (int j = i + 1; j <= v; j++)
            ans = min(ans, arr[i][j] + arr[j][i]);

    cout << (ans < INF ? ans : -1);
}