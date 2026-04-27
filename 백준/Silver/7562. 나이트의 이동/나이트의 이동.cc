#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int l;
pair<int, int> cur, target;

int bfs() {
    int direction[8][2] = {{-2, 1}, {-1, 2},
                           {1, 2}, {2, 1},
                           {2, -1}, {1, -2},
                           {-1, -2}, {-2, -1}};
    vector<vector<int>> dp(l, vector<int>(l, -1));
    queue<pair<int, int>> q;
    q.push(cur);
    dp[cur.first][cur.second] = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (target.first == y && target.second == x)
            return dp[y][x];

        for (int* dir : direction) {
            int dy = y + dir[0];
            int dx = x + dir[1];

            if (dy < 0 || dy >= l || dx < 0 || dx >= l)
                continue;

            if (dp[dy][dx] == -1) {
                dp[dy][dx] = dp[y][x] + 1;
                q.emplace(dy, dx);
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        cin >> l;
        cin >> cur.first >> cur.second;
        cin >> target.first >> target.second;

        cout << bfs() << '\n';
    }
}