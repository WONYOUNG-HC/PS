#include <iostream>
#include <cstring>
#include <queue>
#include <numeric>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

int n, m, d;
int arr[20][20], narr[20][20];
bool cut[20][20];
int dir[3][2] = {{0, -1}, {-1, 0}, {0, 1}};

int dist(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

void bfs(int c) {
    bool vis[20][20];
    memset(vis, false, sizeof(bool) * 20 * 20);
    queue<pii> q;
    q.emplace(n, c);

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int *dr : dir) {
            int dy = y + dr[0];
            int dx = x + dr[1];
            
            if (dy == n || dy < 0 || dx < 0 || dx > m)
                continue;
            if (vis[dy][dx])
                continue;
            if (dist(dy, dx, n, c) > d)
                continue;

            if (narr[dy][dx] == 1) {
                cut[dy][dx] = true;
                return;
            }

            q.emplace(dy, dx);
            vis[dy][dx] = true;    
        }
    }
}

int main() {
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                memcpy(narr, arr, sizeof(int) * 20 * 20);

                int cnt = 0;
                while (true) {
                    int sum = 0;
                    for (int l = 0; l < n; l++) 
                        sum += accumulate(narr[l], narr[l] + 20, 0);
                    if (sum == 0)
                        break;

                    memset(cut, false, sizeof(bool) * 20 * 20);
                    bfs(i);
                    bfs(j);
                    bfs(k);

                    for (int l = 0; l < n; l++) {
                        for (int o = 0; o < m; o++) {
                            if (cut[l][o]) {
                                narr[l][o] = 0;
                                cnt++;
                            }
                        }
                    }

                    for (int l = n - 1; l > 0; l--) 
                        for (int o = 0; o < m; o++) 
                            narr[l][o] = narr[l - 1][o];

                    for (int l = 0; l < m; l++)
                        narr[0][l] = 0;
                }

                ans = max(ans, cnt);
            }
        }
    }

    cout << ans;
}