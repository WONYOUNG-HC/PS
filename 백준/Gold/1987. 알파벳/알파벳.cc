#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
int ans;
vector<string> graph;

void dfs(vector<bool>& visited, int y, int x, int cnt);

int main() {
    cin >> r >> c;

    graph.resize(r);
    for (int i = 0; i < r; i++)
        cin >> graph[i];

    vector<bool> visited(26);
    visited[graph[0][0] - 'A'] = true;
    dfs(visited, 0, 0, 1);

    cout << ans;
}

int direction[4][2] = {{-1, 0}, {1, 0},
                       {0, -1}, {0, 1}};

void dfs(vector<bool>& visited, int y, int x, int cnt) {
    ans = max(ans, cnt);

    for (int* dir : direction) {
        int dy = y + dir[0];
        int dx = x + dir[1];

        if (dy < 0 || dy >= r || dx < 0 || dx >= c)
            continue;

        if (!visited[graph[dy][dx] - 'A']) {
            visited[graph[dy][dx] - 'A'] = true;
            dfs(visited, dy, dx, cnt + 1);
            visited[graph[dy][dx] - 'A'] = false;
        }
    }
}