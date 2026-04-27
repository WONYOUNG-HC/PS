#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int w, h;
char arr[30][30];
pii cleaner;
vector<pii> target;
int dist[20][20];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int inf = 1e8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> w >> h;

        if (w + h == 0) {
            break;
        }

        fill_n(&arr[0][0], 30 * 30, 'x');
        target.clear();

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> arr[i][j];

                if (arr[i][j] == 'o') {
                    cleaner = {i, j};
                    arr[i][j] = '.';
                } else if (arr[i][j] == '*') {
                    target.push_back({i, j});
                    arr[i][j] = '.';
                }
            }
        }

        target.insert(target.begin(), cleaner);

        //
        //
        //
        
        fill_n(&dist[0][0], 20 * 20, inf);

        for (int i = 0; i < target.size(); i++) {
            for (int j = i + 1; j < target.size(); j++) {
                queue<pii> q;
                int vis[30][30];

                fill_n(&vis[0][0], 30 * 30, inf);
                vis[target[i].first][target[i].second] = 0;
                q.push(target[i]);

                while (!q.empty()) {
                    int y, x;
                    tie(y, x) = q.front();
                    q.pop();

                    if (y == target[j].first && x == target[j].second) {
                        break;
                    }

                    for (int *d : dir) {
                        int dy = y + d[0];
                        int dx = x + d[1];

                        if (arr[dy][dx] == '.' && vis[dy][dx] > vis[y][x] + 1) {
                            vis[dy][dx] = vis[y][x] + 1;
                            q.push({dy, dx});
                        }
                    }
                }

                dist[i][j] = vis[target[j].first][target[j].second];
                dist[j][i] = vis[target[j].first][target[j].second];
            }
        }

        //
        //
        //

        vector<int> order;

        for (int i = 1; i < target.size(); i++) {
            order.push_back(i);
        }

        int answer = inf;

        do {
            int ret = dist[0][order[0]];

            for (int i = 1; i < order.size(); i++) {
                ret += dist[order[i - 1]][order[i]];
            }

            answer = min(answer, ret);
        } while (next_permutation(order.begin(), order.end()));

        if (answer >= inf) {
            cout << -1 << '\n';
        } else {
            cout << answer << '\n';
        }
    }
}