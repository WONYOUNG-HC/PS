#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Bfs(vector<vector<int>>& board, vector<vector<bool>>& visited, int n, int m, int& max, int y, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> board[i][j];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int max = 0, cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                Bfs(board, visited, n, m, max, i, j);
                cnt++;
            }
        }
    }

    cout << cnt << ' ' << max;
}

void Bfs(vector<vector<int>>& board, vector<vector<bool>>& visited, int n, int m, int& max, int y, int x) {
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    q.emplace(y, x);
    visited[y][x] = true;
    int size = 1;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (auto& dir : direction) {
            int ny = i + dir[0];
            int nx = j + dir[1];

            if (0 <= ny && ny < n && 0 <= nx && nx < m && board[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.emplace(ny, nx);
                size++;
            }
        }
    }

    if (size > max) max = size;
}