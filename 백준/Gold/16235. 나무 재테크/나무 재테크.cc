#include <iostream>
#include <deque>

using namespace std;

int n, m, k;
int arr[20][20];
int s2d2[20][20];
deque<int> tree[20][20];
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},
                 {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s2d2[i][j];
            arr[i][j] = 5;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    while (k--) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int sz = tree[i][j].size();
                int dead = 0;

                while (sz--) {
                    if (tree[i][j].front() <= arr[i][j]) {
                        arr[i][j] -= tree[i][j].front();
                        tree[i][j].push_back(tree[i][j].front() + 1);
                    }
                    else {
                        dead += tree[i][j].front() / 2;
                    }

                    tree[i][j].pop_front();
                }

                arr[i][j] += dead;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int a : tree[i][j]) {
                    if (a % 5 == 0) {
                        for (int* d : dir) {
                            int dy = i + d[0];
                            int dx = j + d[1];

                            tree[dy][dx].push_front(1);
                        }
                    }
                }

                arr[i][j] += s2d2[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans += tree[i][j].size();

    cout << ans;
}