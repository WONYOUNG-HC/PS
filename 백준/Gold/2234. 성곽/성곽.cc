#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, m;
vector<vector<int>> wall;
vector<vector<pair<int, int>>> area;

void Input();
void bfs(int y, int x, int cnt);
int FindMaxArea();
int Conquer();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Input();

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (area[i][j].second == -1) {
                bfs(i, j, cnt);
                cnt++;
            }
        }
    }

    int max_area = FindMaxArea();

    int conquer = Conquer();

    cout << cnt << '\n' << max_area << '\n' << conquer;
}

void Input() {
    cin >> n >> m;

    wall.resize(m + 2, vector<int>(n + 2));
    area.resize(m + 2, vector<pair<int, int>>(n + 2, {-INF, -1}));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> wall[i][j];
}

void bfs(int y, int x, int cnt) {
    int direction[4][2] = {{0,  -1},
                           {-1, 0},
                           {0,  1},
                           {1,  0}};

    vector<pair<int, int>> same;
    queue<pair<int, int>> q;
    same.emplace_back(y, x);
    q.emplace(y, x);
    area[y][x].second = cnt;

    while (!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (wall[ny][nx] & (1 << i))
                continue;

            int dy = ny + direction[i][0];
            int dx = nx + direction[i][1];

            if (area[dy][dx].second == -1) {
                area[dy][dx].second = cnt;
                same.emplace_back(dy, dx);
                q.emplace(dy, dx);
            }
        }
    }

    int width = (int)same.size();
    for (pair<int, int>& pos : same) {
        area[pos.first][pos.second].first = width;
    }
}

int FindMaxArea() {
    int ret = 0;

    for (int i = 1; i <= m; i++)
        ret = max(ret, (*max_element(area[i].begin(), area[i].end())).first);

    return ret;
}

int Conquer() {
    int direction[2][2] = {{0, 1}, {1, 0}};

    int ret = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int* dir : direction) {
                int di = i + dir[0];
                int dj = j + dir[1];

                if (area[i][j].second != area[di][dj].second) {
                    ret = max(ret, area[i][j].first + area[di][dj].first);
                }
            }
        }
    }

    return ret;
}