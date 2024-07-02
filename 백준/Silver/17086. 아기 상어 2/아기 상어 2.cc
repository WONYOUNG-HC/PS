#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int n, m;
int arr[55][55];
bool vis[55][55];
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int main() {
    cin >> n >> m;

    queue<pii> q1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q1.emplace(i, j);
                vis[i][j] = true;
            }
        }
    }

    queue<pii> q2;
    int ans = -1;
    while (!q1.empty()) {
        while (!q1.empty()) {
            int y = q1.front().first;
            int x = q1.front().second;
            q1.pop();

            for (int *d : dir) {
                int dy = y + d[0];
                int dx = x + d[1];

                if (dy < 1 || dy > n || dx < 1 || dx > m)
                    continue;
                if (vis[dy][dx])
                    continue;
                
                vis[dy][dx] = true;
                q2.emplace(dy, dx);
            }
        }

    q1.swap(q2);
    ans++;
    }

    cout << ans;
}