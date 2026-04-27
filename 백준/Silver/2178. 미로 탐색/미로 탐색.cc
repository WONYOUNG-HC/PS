#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int graph[101][101];
vector<vector<int>> dp(101);


void Bfs(int n, int m);

int main() {
    int n, m;
    cin >> n >> m;

    for (int i=1; i<n+1; i++) {
        for (int j=1; j<m+1; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    for (int i=1; i<n+1; i++)
        dp[i].resize(m+1, 10001);

    Bfs(n, m);
}

void Bfs(int n, int m) {
    queue<pair<int, int>> q;
    q.push(pair<int, int>(1, 1));
    dp[1][1] = 1;

    pair<int, int> pr;
    while (!q.empty()) {
        pr = q.front();
        q.pop();

        int ny, nx;
        for (int i=0; i<4; i++) {
            ny = pr.first + dy[i];
            nx = pr.second + dx[i];

            if (ny < 1 || ny > n || nx < 1 || nx > m)
                continue;

            if (ny == n && nx == m) {
                cout << dp[pr.first][pr.second] + 1;
                return;
            }

            if (!graph[ny][nx])
                continue;

            if (dp[pr.first][pr.second] + 1 < dp[ny][nx]) {
                dp[ny][nx] = dp[pr.first][pr.second] + 1;
                q.push(pair<int, int>(ny, nx));
            }
        }
    }
}