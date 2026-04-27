#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define Y first
#define X second

using namespace std;

int n, m;
int wall_cnt;
int graph[10][10];
vector<pair<int, int>> space;
vector<vector<pair<int, int>>> wall;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void permutation(vector<pair<int, int>>& v, int idx, int cnt) {
    if (cnt == 3) {
        wall.push_back(v);
        return;
    }

    for (int i = idx; i < space.size(); i++) {
        if (i + (3 - cnt) > space.size())
            break;

        v.push_back(space[i]);
        permutation(v, i + 1, cnt + 1);
        v.pop_back();
    }
}

int bfs(vector<pair<int, int>>& w) {
    int board[10][10];
    memcpy(board, graph, sizeof(graph));

    for (pair<int, int>& pr : w)
        board[pr.Y][pr.X] = 1;

    bool vis[10][10] = {false, };
    int area = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == 2 && !vis[i][j]) {
                queue<pair<int, int>> q;
                q.emplace(i, j);
                vis[i][j] = true;
                area++;

                while (!q.empty()) {
                    int y = q.front().Y;
                    int x = q.front().X;
                    q.pop();

                    for (int* dir : direction) {
                        int dy = y + dir[0];
                        int dx = x + dir[1];

                        if ((board[dy][dx] == 0 || board[dy][dx] == 2) && !vis[dy][dx]) {
                            board[dy][dx] = 2;
                            q.emplace(dy, dx);
                            vis[dy][dx] = true;
                            area++;
                        }
                    }
                }
            }
        }
    }

    return (n * m) - area - (wall_cnt + 3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    memset(graph, -1, sizeof(graph));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 1) wall_cnt++;
            if (graph[i][j] == 0) space.emplace_back(i, j);
        }
    }

    vector<pair<int, int>> v;
    permutation(v, 0, 0);

    int ans = 0;
    for (auto& w : wall)
        ans = max(ans, bfs(w));

    cout << ans;
}