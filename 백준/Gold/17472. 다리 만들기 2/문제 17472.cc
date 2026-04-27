#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n, m;
int arr[20][20];
int island[20][20];
int graph[10][10];
int vis[10];
vector<pair<int, pii>> edge;
int parent[10];
int level[10];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int inf = 1e9;

int find(int x) {
    if (x == parent[x]) {
        return x;
    }

    return parent[x] = find(parent[x]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) {
        return false;
    }

    if (level[u] < level[v]) {
        swap(u, v);
    }

    parent[v] = u;

    if (level[u] == level[v]) {
        level[u] += 1;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fill_n(&arr[0][0], 20 * 20, -1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    //
    //
    //

    fill_n(&island[0][0], 20 * 20, -1);

    int island_num = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0) {
                island[i][j] = 0;
            }

            if (island[i][j] != -1) {
                continue;
            }
            
            queue<pii> q;

            island_num += 1;
            island[i][j] = island_num;
            q.push({i, j});

            while (!q.empty()) {
                int y, x;

                tie(y, x) = q.front();
                q.pop();

                for (int *d : dir) {
                    int dy = y + d[0];
                    int dx = x + d[1];

                    if (arr[dy][dx] == 1 && island[dy][dx] <= 0) {
                        island[dy][dx] = island_num;
                        q.push({dy, dx});
                    }
                }
            }
        }
    }

    //
    //
    //

    fill_n(&graph[0][0], 10 * 10, inf);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (island[i][j] == 0) {
                continue;
            }

            int y = i;
            int x = j;

            fill_n(vis, 10, false);

            vis[island[i][j]] = true;

            for (int *d : dir) {
                int length = 1;

                for (int k = 1; k <= 10; k++) {
                    int dy = y + (d[0] * k);
                    int dx = x + (d[1] * k);

                    if (island[dy][dx] == -1) {
                        break;
                    }

                    if (island[dy][dx] == island[y][x]) {
                        break;
                    }

                    if (island[dy][dx] > 0 && !vis[island[dy][dx]] && length > 2) {
                        int u = island[y][x];
                        int v = island[dy][dx];

                        graph[u][v] = min(graph[u][v], length - 1);
                        graph[v][u] = min(graph[v][u], length - 1);
                    }

                    if (island[dy][dx] > 0) {
                        vis[island[dy][dx]] = true;
                        break;
                    }

                    length += 1;
                }
            }
        }
    }

    //
    //
    //

    int ans = 0;
    int cnt = 0;

    for (int i = 1; i <= island_num; i++) {
        for (int j = 1; j < i; j++) {
            if (graph[i][j] < inf) {
                edge.push_back({graph[i][j], {i, j}});
            }
        }
    }

    for (int i = 1; i <= island_num; i++) {
        parent[i] = i;
        level[i] = 1;
    }

    sort(edge.begin(), edge.end());

    for (auto e : edge) {
        int cost = e.first;
        int u, v;

        tie(u, v) = e.second;

        if (merge(u, v)) {
            ans += cost;
            cnt += 1;
        }

        if (cnt == island_num - 1) {
            break;
        }
    }

    //
    //
    //

    if (cnt < island_num - 1) {
        ans = -1;
    }

    cout << ans;
}