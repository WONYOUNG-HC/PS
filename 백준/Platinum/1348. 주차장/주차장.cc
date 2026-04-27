#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9
#define Y first
#define X second

using namespace std;

int r, c;
vector<vector<char>> board;
vector<pair<int, int>> car, park;
vector<vector<int>> graph, dist;
vector<int> match;
vector<int> vis;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void BFS(int y, int x, int idx) {
    vector<vector<int>> d(r + 2, vector<int>(c + 2, INF));
    queue<pair<int, int>> q;
    q.emplace(y, x);
    d[y][x] = 0;

    while (!q.empty()) {
        int ny = q.front().Y;
        int nx = q.front().X;
        q.pop();

        for (int* dir : direction) {
            int dy = ny + dir[0];
            int dx = nx + dir[1];

            if (board[dy][dx] != 'X' && d[dy][dx] > d[ny][nx] + 1) {
                d[dy][dx] = d[ny][nx] + 1;
                q.emplace(dy, dx);
            }
        }
    }

    for (int i = 0; i < park.size(); i++) {
        dist[idx][i] = d[park[i].Y][park[i].X];

        if (dist[idx][i] != INF)
            graph[idx].push_back(i);
    }
}

bool DFS(int x, int time) {
    if (vis[x])
        return false;
    vis[x] = true;

    for (int y : graph[x]) {
        if (dist[x][y] <= time && (match[y] == -1 || DFS(match[y], time))) {
            match[y] = x;
            return true;
        }
    }

    return false;
}

bool Matching(int time) {
    fill(match.begin(), match.end(), -1);

    int m = 0;
    for (int i = 0; i < car.size(); i++) {
        fill(vis.begin(), vis.end(), false);

        if (DFS(i, time))
            m++;
    }

    return m == car.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    board.resize(r + 2, vector<char>(c + 2, 'X'));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> board[i][j];

            if (board[i][j] == 'C')
                car.emplace_back(i, j);
            else if (board[i][j] == 'P')
                park.emplace_back(i, j);
        }
    }

    if (car.empty()) {
        cout << 0;
        return 0;
    }

    if (car.size() > park.size()) {
        cout << -1;
        return 0;
    }

    graph.resize(car.size());
    dist.resize(car.size(), vector<int>(park.size()));
    for (int i = 0; i < car.size(); i++)
        BFS(car[i].Y, car[i].X, i);

    match.resize(park.size());
    vis.resize(car.size());

    int left = 0, right = r * c;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (Matching(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << (left > r * c ? -1 : left);
}