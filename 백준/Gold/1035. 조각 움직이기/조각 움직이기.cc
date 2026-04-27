#include <iostream>
#include <queue>
#include <set>
#include <cstdlib>

using namespace std;
using vvb = vector<vector<bool>>;

int k;
queue<pair<vvb, int>> q;
set<int> vis;
int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

bool chk(int y, int x) {
    return 0 <= y && y <= 4 && 0 <= x && x <= 4;
}

int to_beat(vvb &v) {
    int ret = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ret |= v[i][j];
            ret <<= 1;
        }
    }

    return ret;
}

bool connect(vvb &v) {
    vvb visited(5, vector<bool>(5, false));
    queue<pair<int, int>> q;

    int total = 0;
    int connected = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 ; j++) {
            if (v[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
                break;
            }
        }

        if (q.size() > 0) {
            break;
        }
    }
    
    connected = 1;

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        for (int d = 0; d < 4; d++) {
            int ny = y + dir[d][0];
            int nx = x + dir[d][1];

            if (chk(ny, nx) && v[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;
                connected++;
                q.push({ny, nx});
            }
        }
    }

    return connected == k;
}

int main() {
    vvb arr(5, vector<bool>(5));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char b;

            cin >> b;
            arr[i][j] = b == '*';

            if (arr[i][j]) {
                k += 1;
            }
        }
    }

    q.push({arr, 0});

    while (true) {
        auto [v, cnt] = q.front();

        q.pop();

        bool flag = true;

        if (connect(v)) {
            cout << cnt;

            exit(0);
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (v[i][j]) {
                    for (int *d : dir) {
                        int ni = i + d[0];
                        int nj = j + d[1];
                        
                        if (!chk(ni, nj) || v[ni][nj]) {
                            continue;
                        }

                        swap(v[i][j], v[ni][nj]);

                        int beat = to_beat(v);

                        if (vis.find(beat) == vis.end()) {
                            vis.insert(beat);

                            q.push({v, cnt + 1});
                        }

                        swap(v[i][j], v[ni][nj]);
                    }
                }
            }
        }
    }
}