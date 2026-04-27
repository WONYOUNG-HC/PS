#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int n, m, k;
int arr[30][30];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Dice {
public:
    int y = 1;
    int x = 1;
    
    int top = 1;
    int right = 3;
    int bottom = 6;
    int left = 4;
    int front = 5;
    int back = 2;

    int d = 0;

    void toRight() {
        swap(top, right);
        swap(top, bottom);
        swap(top, left);
    }

    void toLeft() {
        swap(top, left);
        swap(top, bottom);
        swap(top, right);
    }

    void toFront() {
        swap(top, front);
        swap(top, bottom);
        swap(top, back);
    }

    void toBack() {
        swap(top, back);
        swap(top, bottom);
        swap(top, front);
    }

    void roll() {
        function<void()> actions[4] = {
            [this]() { 
                this->toRight(); 
            },
            [this]() {
                this->toFront();
            },
            [this]() {
                this->toLeft();
            },
            [this]() {
                this->toBack();
            }
        };

        int dy = y + dir[d][0];
        int dx = x + dir[d][1];

        if (arr[dy][dx] == 0) {
            d = (d + 2) % 4;
            dy = y + dir[d][0];
            dx = x + dir[d][1];
        }

        actions[d]();

        y = dy;
        x = dx;
    }
};

int bfs(int y, int x) {
    bool vis[30][30] = {};
    queue<pair<int, int>> q;
    int ret = 1;

    vis[y][x] = true;
    q.push({y, x});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int *d : dir) {
            int dy = cur.first + d[0];
            int dx = cur.second + d[1];

            if (arr[dy][dx] == 0) {
                continue;
            }

            if (vis[dy][dx]) {
                continue;
            }

            if (arr[dy][dx] != arr[y][x]) {
                continue;
            }

            vis[dy][dx] = true;
            q.push({dy, dx});
            ret += 1;
        }
    }

    return ret * arr[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    Dice dice;

    while (k--) {
        dice.roll();

        ans += bfs(dice.y, dice.x);
        
        int a = dice.bottom;
        int b = arr[dice.y][dice.x];

        if (a > b) {
            dice.d = (dice.d + 1) % 4;
        } else if (a < b) {
            dice.d = (dice.d - 1 + 4) % 4;
        }
    }

    cout << ans;
}