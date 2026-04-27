#include <iostream>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

int n;
bool arr[110][110];
pii pos[30];
vector<int> dragon[30];
int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        pos[i] = {x, y};
        dragon[i].push_back(d);

        for (int j = 0; j < g; j++) {
            int len = dragon[i].size();
            for (int k = len - 1; k >= 0; k--) {
                dragon[i].push_back((dragon[i][k] + 1) % 4);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int y = pos[i].Y, x = pos[i].X;
        arr[y][x] = true;

        for (int d : dragon[i]) {
            int dy = y + dir[d][0];
            int dx = x + dir[d][1];

            if (dy < 0 || dy > 100 || dx < 0 || dx > 100)
                continue;

            arr[dy][dx] = true;
            y = dy, x = dx;
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1] && ans++;

    cout << ans;
}