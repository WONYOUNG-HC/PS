#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using pii = pair<int, int>;

int n, m;
int arr[60][60];
vector<pii> positions;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int answer = 1e9;

int bfs(vector<pii> &virus) {
    bool vis[60][60] = {0, };
    queue<pair<pii, int>> q;

    for (auto v : virus) {
        int y = v.first;
        int x = v.second;

        vis[y][x] = true;
        q.push({{y, x}, 0});
    }

    //
    //
    //

    int last_time = 0;
    
    while (!q.empty()) {
        pii pos = q.front().first;
        int y = pos.first;
        int x = pos.second;
        int time = q.front().second;

        q.pop();

        for (int *d : dir) {
            int dy = y + d[0];
            int dx = x + d[1];

            if (arr[dy][dx] != 1 && !vis[dy][dx]) {
                vis[dy][dx] = true;
                last_time = time + 1;
                
                q.push({{dy, dx}, time + 1});
            }
        }
    }

    //
    //
    //

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != 1 && !vis[i][j]) {
                return 1e9;
            }
        }
    }

    return last_time;
}

void combination(int start, vector<pii> &current) {
    if (current.size() == m) {
        answer = min(answer, bfs(current));
        return;
    }

    for (int i = start; i < positions.size(); i++) {
        current.push_back(positions[i]);
        combination(i + 1, current);
        current.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    fill_n(&arr[0][0], 60 * 60, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 2) {
                positions.push_back({i, j});
                arr[i][j] = 0;
            }
        }
    }

    //
    //
    //

    vector<pii> current;

    combination(0, current);

    if (answer == 1e9) {
        answer = -1;
    }

    cout << answer;
}