#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int dist[210][210];
int from[20010];
int to[20010];
int cost[20010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fill_n(&dist[0][0], 210 * 210, 1e9);

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> cost[i];

        dist[from[i]][to[i]] = min(dist[from[i]][to[i]], cost[i]);
        dist[to[i]][from[i]] = min(dist[to[i]][from[i]], cost[i]);
    }

    //
    //
    //

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    //
    //
    //
    
    int ans = 1e9;

    for (int i = 1; i <= n; i++) {
        int mx = 0;

        for (int j = 0; j < m; j++) {
            mx = max(mx, dist[i][from[j]] + dist[i][to[j]] + cost[j]);
        }

        ans = min(ans, mx);
    }

    cout << fixed;
    cout.precision(1);
    cout << ans / 2.0;
}