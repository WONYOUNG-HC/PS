#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
char arr[60][60];
int dist[60][60];
bool vis[60][60];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 'L') {
                queue<pair<int, int>> q;
                priority_queue<int> pq;
                q.emplace(i, j);
                pq.push(0);
                vis[i][j] = true;

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int* d : dir) {
                        int dy = y + d[0];
                        int dx = x + d[1];

                        if (arr[dy][dx] == 'L' && !vis[dy][dx]) {
                            dist[dy][dx] = dist[y][x] + 1;
                            vis[dy][dx] = true;
                            q.emplace(dy, dx);
                            pq.push(dist[dy][dx]);
                        }
                    }
                }

                ans = max(ans, pq.top());
                fill_n(&dist[0][0], 60 * 60, 0);
                fill_n(&vis[0][0], 60 * 60, false);
            }
        }
    }

    cout << ans;
}