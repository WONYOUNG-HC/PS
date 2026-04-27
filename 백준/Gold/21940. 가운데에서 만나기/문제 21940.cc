#include <iostream>
#include <set>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, m, k;
int arr[210][210], dist[210][210];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fill_n(&arr[0][0], 210 * 210, INF);
    for (int i = 1; i <= n; i++) arr[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    for (int l = 1; l <= n; l++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                arr[i][j] = min(arr[i][j], arr[i][l] + arr[l][j]);

    cin >> k;
    for (int i = 0; i < k; i++) {
        int c; cin >> c;

        dist[i][0] = c;
        for (int j = 1; j <= n; j++)
            dist[i][j] = arr[c][j] + arr[j][c];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            dist[k][i] = max(dist[k][i], dist[j][i]);

    set<int> ans = {1};
    for (int i = 2; i <= n; i++) {
        if (dist[k][i] < dist[k][*ans.begin()]) {
            ans.clear();
            ans.insert(i);
        }
        if (dist[k][i] == dist[k][*ans.begin()]) {
            ans.insert(i);
        }
    }

    for (auto& x : ans) cout << x << ' ';
}