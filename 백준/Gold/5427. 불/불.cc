#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int w, h;
char graph[1010][1010];
bool vis[1010][1010];
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool bfs(queue<pair<int, int>>& q1, queue<pair<int, int>>& q2, char c) {
    while (!q1.empty()) {
        int y = q1.front().first;
        int x = q1.front().second;
        q1.pop();

        if (c == '@' && (y == 1 || y == h || x == 1 || x == w))
            return true;

        for (int* dir : direction) {
            int dy = y + dir[0];
            int dx = x + dir[1];

            if (c == '*' && (graph[dy][dx] == '.' || graph[dy][dx] == '@')) {
                graph[dy][dx] = '*';
                q2.emplace(dy, dx);
            }
            if (c == '@' && (graph[dy][dx] == '.')) {
                graph[dy][dx] = '@';
                q2.emplace(dy, dx);
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        memset(graph, 'o', sizeof(char) * 1010 * 1010);
        memset(vis, 0, sizeof(bool) * 1010 * 1010);

        cin >> w >> h;

        queue<pair<int, int>> pos1, pos2, fire1, fire2;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> graph[i][j];

                if (graph[i][j] == '@')
                    pos1.emplace(i, j);
                if (graph[i][j] == '*')
                    fire1.emplace(i, j);
            }
        }

        int time = 1;
        bool flag = false;
        while (!pos1.empty() || !fire1.empty()) {
            bfs(fire1, fire2, '*');
            fire1.swap(fire2);

            if (bfs(pos1, pos2, '@')) {
                flag = true;
                break;
            }
            pos1.swap(pos2);

            time++;
        }

        if (flag)
            cout << time << '\n';
        else
            cout << "IMPOSSIBLE" << '\n';
    }
}