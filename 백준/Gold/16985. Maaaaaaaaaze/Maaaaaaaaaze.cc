#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n = 5;
int dir[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
vector<vector<vector<int>>> arr(n + 2, vector<vector<int>>(n + 2, vector<int>(n + 2, 0)));
vector<vector<vector<int>>> maze(n + 2, vector<vector<int>>(n + 2, vector<int>(n + 2, 0)));
vector<vector<vector<vector<int>>>> rotate_cache(n + 2);

vector<vector<int>> rotate(const vector<vector<int>> &prev) {
    vector<vector<int>> next(n + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            next[j][n + 1 - i] = prev[i][j];
        }
    }

    return next;
}

int bfs() {
    int ret = 1e9;
    vector<int> start = {1, 1, 1};
    vector<int> dest = {n, n, n};
    queue<vector<int>> q;
    vector<vector<vector<bool>>> vis(n + 2, vector<vector<bool>>(n + 2, vector<bool>(n + 2, false)));

    if (maze[start[0]][start[1]][start[2]] == 0 || maze[dest[0]][dest[1]][dest[2]] == 0) {
        return ret;
    }

    vis[start[0]][start[1]][start[2]] = true;
    q.push({start[0], start[1], start[2], 0});

    while (!q.empty()) {
        auto pop_q = q.front();
        int z = pop_q[0];
        int y = pop_q[1];
        int x = pop_q[2];
        int cur = pop_q[3];

        q.pop();

        if (z == dest[0] && y == dest[1] && x == dest[2]) {
            ret = min(ret, cur);
            break;
        }

        for (int *d : dir) {
            int dz = z + d[0];
            int dy = y + d[1];
            int dx = x + d[2];

            if (maze[dz][dy][dx] == 1 && !vis[dz][dy][dx]) {
                vis[dz][dy][dx] = true;
                q.push({dz, dy, dx, cur + 1});
            }
        }
    }

    return ret;
}

void permutation(vector<int> &current, vector<vector<int>> &result) {
    if (current.size() == n + 1) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < 4; i++) {
        current.push_back(i);
        permutation(current, result);
        current.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> arr[i][j][k];
            }
        }
    }

    //
    //
    //

    for (int i = 1; i <= n; i++) {
        rotate_cache[i].push_back(arr[i]);

        for (int j = 1; j < 4; j++) {
            rotate_cache[i].push_back(rotate(rotate_cache[i][j - 1]));
        }
    }

    //
    //
    //

    int answer = 1e9;
    vector<int> board_order = {1, 2, 3, 4, 5};

    do {
        vector<vector<int>> rotate_orders;
        vector<int> rotate_current(1);

        permutation(rotate_current, rotate_orders);

        for (auto rotate_order : rotate_orders) {
            for (int i = 1; i <= n; i++) {
                int maze_depth = board_order[i - 1];
                int rotate_count = rotate_order[i];
                
                maze[i] = rotate_cache[maze_depth][rotate_count];
            }

            answer = min(answer, bfs());
        }
    } while (next_permutation(board_order.begin(), board_order.end()));


    if (answer == 1e9) {
        answer = -1;
    }

    cout << answer;
}