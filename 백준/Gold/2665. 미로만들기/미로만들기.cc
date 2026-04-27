#include <iostream>
#include <tuple>
#include <deque>

using namespace std;

int n;
char graph[55][55];
bool vis[55][55];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> graph[i][j];

    deque<tuple<int, int, int>> dq;
    dq.emplace_back(0, 1, 1);
    vis[1][1] = true;

    while (!dq.empty()) {
        int cost = get<0>(dq.front());
        int y = get<1>(dq.front());
        int x = get<2>(dq.front());
        dq.pop_front();

        if (y == n && x == n) {
            cout << cost;
            return 0;
        }

        for (int* d : dir) {
            int dy = y + d[0];
            int dx = x + d[1];

            if (dy < 1 || dy > n || dx < 1 || dx > n)
                continue;

            if (vis[dy][dx])
                continue;
            vis[dy][dx] = true;

            if (graph[dy][dx] == '0')
                dq.emplace_back(cost + 1, dy, dx);
            else
                dq.emplace_front(cost, dy, dx);
        }
    }
}