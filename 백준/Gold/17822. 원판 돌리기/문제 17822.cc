#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, t;
vector<vector<int>> arr(60, vector<int>(60));
bool del[60][60];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void f(int i, int d) {
    vector<int> v(60);
    
    for (int j = 1; j <= m; j++) {
        int jj = (j + (d == 0 ? 1 : -1) + m - 1) % m + 1;

        v[jj] = arr[i][j];
    }

    arr[i] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    while (t--) {
        int x, d, k;

        cin >> x >> d >> k;

        for (int i = 1; x * i <= n; i++) {
            for (int j = 0; j < k; j++) {
                f(x * i, d);
            }
        }

        //
        //
        //

        bool is_del = false;

        fill_n(&del[0][0], 60 * 60, false);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 0) {
                    continue;
                }

                for (int *d : dir) {
                    int dy = i + d[0];
                    int dx = (j + d[1] + m - 1) % m + 1;

                    if (arr[dy][dx] == arr[i][j]) {
                        del[i][j] = true;
                        del[dy][dx] = true;
                        is_del = true;
                    }
                }
            }
        }

        if (is_del) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (del[i][j]) {
                        arr[i][j] = 0;
                    }
                }
            }

            continue;
        }

        //
        //
        //


        double sum = 0;
        double cnt = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 0) {
                    continue;
                }

                sum += arr[i][j];
                cnt += 1;
            }
        }

        double avarage = sum / cnt;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 0) {
                    continue;
                }

                if (arr[i][j] > avarage) {
                    arr[i][j] -= 1;
                } else if (arr[i][j] < avarage) {
                    arr[i][j] += 1;
                }
            }
        }
    }

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum += arr[i][j];
        }
    }

    cout << sum;
}