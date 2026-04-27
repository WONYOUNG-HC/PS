#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int r, c;
char arr[1510][1510];
vector<pii> ducks;
pii parent[1510][1510];
int level[1510][1510];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pii find(pii u) {
    if (u == parent[u.first][u.second]) {
        return u;
    }

    return parent[u.first][u.second] = find(parent[u.first][u.second]);
}

void merge(pii u, pii v) {
    u = find(u);
    v = find(v);

    if (u == v) {
        return;
    }

    if (level[u.first][u.second] < level[v.first][v.second]) {
        swap(u, v);
    }

    parent[v.first][v.second] = u;

    if (level[u.first][u.second] == level[v.first][v.second]) {
        level[u.first][u.second] += 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    fill(&arr[0][0], &arr[0][0] + 1510 * 1510, '-');

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 'L') {
                ducks.emplace_back(i, j);
                arr[i][j] = '.';
            }
        }
    }

    //
    //
    //

    vector<pii> v;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            parent[i][j] = {i, j};
            level[i][j] = 1;
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (arr[i][j] == 'X') {
                continue;
            }

            for (int *d : dir) {
                int dy = i + d[0];
                int dx = j + d[1];

                if (arr[dy][dx] == '.') {
                    merge({i, j}, {dy, dx});
                } else if (arr[dy][dx] == 'X') {
                    v.emplace_back(i, j);
                }
            }
        }
    }

    //
    //
    //

    int answer = 0;

    while (find(ducks[0]) != find(ducks[1])) {
        vector<pii> _v;

        for (auto pos : v) {
            for (int *d : dir) {
                int dy = pos.first + d[0];
                int dx = pos.second + d[1];

                if (arr[dy][dx] == 'X') {
                    arr[dy][dx] = '.';
                    _v.emplace_back(dy, dx);

                    merge(pos, {dy, dx});

                    for (int *dd : dir) {
                        int ddy = dy + dd[0];
                        int ddx = dx + dd[1];

                        if (arr[ddy][ddx] == '.') {
                            merge({dy, dx}, {ddy, ddx});
                        }
                    }
                }
            }
        }

        v.swap(_v);
        answer += 1;
    }

    cout << answer;
}