#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

#define LOOP for (int k = 1; k <= h; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)

using namespace std;

int m, n, h;
int graph[110][110][110];
int direction[6][3] = {{-1, 0, 0}, {1, 0, 0},
                       {0, -1, 0}, {0, 1, 0},
                       {0, 0, -1}, {0, 0, 1}};
queue<tuple<int, int, int>> q1;
queue<tuple<int, int, int>> q2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> h;

    memset(graph, -1, sizeof(int) * 110 * 110 * 110);
    LOOP {
        cin >> graph[k][i][j];
        if (graph[k][i][j] == 1)
            q1.emplace(k, i, j);
    }

    int time = 0;
    while (!q1.empty()) {
        while (!q1.empty()) {
            int z = get<0>(q1.front()), y = get<1>(q1.front()), x = get<2>(q1.front());
            q1.pop();

            for (int* dir : direction) {
                int nz = z + dir[0], ny = y + dir[1], nx = x + dir[2];

                if (graph[nz][ny][nx] == 0) {
                    graph[nz][ny][nx] = 1;
                    q2.emplace(nz, ny, nx);
                }
            }
        }

        time++;
        q1.swap(q2);
    }

    LOOP {
        if (graph[k][i][j] == 0)
        time = 0;
    }

    cout << time - 1;
}