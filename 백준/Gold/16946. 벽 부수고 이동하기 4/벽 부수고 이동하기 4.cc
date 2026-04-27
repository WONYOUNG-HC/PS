#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<string> board;
vector<vector<pair<int, int>>> space;
vector<vector<int>> possible;

void Input();
void bfs(int y, int x, int cnt);
void Count(int y, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    Input();

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == '0' && space[i][j].second == -1) {
                bfs(i, j, cnt);
                cnt++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == '1')
                Count(i, j);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << possible[i][j];
        cout << '\n';
    }
}

void Input() {
    possible.resize(n + 2, vector<int>(m + 2));
    space.resize(n + 2, vector<pair<int, int>>(m + 2, {-1, -1}));
    board.resize(n + 2);

    board[0].resize(m + 2, '1');
    for (int i = 1; i <= n; i++) {
        string line;
        cin >> line;
        board[i] = '1' + line + '1';
    }
    board[n + 1].resize(m + 2, '1');
}

void bfs(int y, int x, int cnt) {
    int direction[4][2] = {{-1, 0},
                           {1, 0},
                           {0, -1},
                           {0, 1}};

    vector<pair<int, int>> route;
    queue<pair<int, int>> q;
    q.emplace(y, x);
    route.emplace_back(y, x);
    space[y][x].second = cnt;

    while (!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();

        for (int* dir : direction) {
            int dy = ny + dir[0];
            int dx = nx + dir[1];

            if (board[dy][dx] == '0' && space[dy][dx].second == -1) {
                q.emplace(dy, dx);
                route.emplace_back(dy, dx);
                space[dy][dx].second = cnt;
            }
        }
    }

    int width = (int)route.size();
    for (pair<int, int>& pr : route)
        space[pr.first][pr.second].first = width;
}

void Count(int y, int x) {
    int direction[4][2] = {{-1, 0},
                           {1, 0},
                           {0, -1},
                           {0, 1}};

    possible[y][x] = 1;
    vector<int> use;

    for (int* dir : direction) {
        int dy = y + dir[0];
        int dx = x + dir[1];

        if (space[dy][dx].second == -1)
            continue;

        bool flag = false;
        for (int num : use) {
            if (num == space[dy][dx].second) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            use.push_back(space[dy][dx].second);
            possible[y][x] += space[dy][dx].first;
            possible[y][x] %= 10;
        }
    }
}