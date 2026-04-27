#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    int lower = INF, upper = 0;
    vector<vector<int>> graph(n + 2, vector<int>(n + 2));

    fill(graph[0].begin(), graph[0].end(), 0);
    for (int i = 1; i <= n; i++) {
        graph[i][0] = 0;
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
            lower = min(lower, graph[i][j]);
            upper = max(upper, graph[i][j]);
        }
        graph[i][n + 1] = 0;
    }
    fill(graph[n + 1].begin(), graph[n + 1].end(), 0);

    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int ans = 1;
    for (int rain = lower; rain <= upper; rain++) {
        int cnt = 0;
        vector<vector<bool>> visited(n + 2, vector<bool>(n + 2));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][j] <= rain || visited[i][j])
                    continue;

                queue<pair<int, int>> q;
                q.emplace(i, j);
                visited[i][j] = true;

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int* dir : direction) {
                        int dy = y + dir[0];
                        int dx = x + dir[1];

                        if (graph[dy][dx] <= rain || visited[dy][dx])
                            continue;

                        q.emplace(dy, dx);
                        visited[dy][dx] = true;
                    }
                }

                cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;
}