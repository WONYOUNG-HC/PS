#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000007

using namespace std;

vector<vector<int>> graph;

void FindRoute(int n, int m, int c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    cin >> n >> m >> c;

    graph.resize(n+1, vector<int>(m+1));
    for (int i = 1; i <= c; i++) {
        int y, x;
        cin >> y >> x;
        graph[y][x] = i;
    }

    FindRoute(n, m, c);
}

void FindRoute(int n, int m, int c) {
    int dp[n+1][m+1][c+1][c+1];
    memset(dp, 0, sizeof(dp));
    graph[1][1] == 0 ? dp[1][1][0][0] = 1 : dp[1][1][graph[1][1]][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;

            if (graph[i][j] > 0) {
                for (int l = 0; l < graph[i][j]; l++) {
                    for (int k = 0; k < graph[i][j]; k++) {
                        dp[i][j][graph[i][j]][l+1] += (dp[i-1][j][k][l] + dp[i][j-1][k][l]);
                        dp[i][j][graph[i][j]][l+1] %= MOD;
                    }
                }
            }
            else {
                for (int k = 0; k <= c; k++) {
                    for (int l = 0; l <= c; l++) {
                        dp[i][j][k][l] += (dp[i-1][j][k][l] + dp[i][j-1][k][l]);
                        dp[i][j][k][l] %= MOD;
                    }
                }
            }
        }
    }

    for (int l = 0; l <= c; l++) {
        int ans = 0;
        for (int k = 0; k <= c; k++) {
            ans += dp[n][m][k][l];
            ans %= MOD;
        }

        cout << ans << ' ';
    }
}