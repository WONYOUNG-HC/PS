#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, r, c;
bool arr[50][50], st[15][15], nst[15][15];

bool overlap(int y, int x) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[y + i][x + j] && st[i][j]) {
                return true;
            }
        }
    }

    return false;
}

bool chk() {
    for (int i = 0; i <= n - r; i++) {
        for (int j = 0; j <= m - c; j++) {
            if (!overlap(i, j)) {
                for (int y = 0; y < r; y++) {
                    for (int x = 0; x < c; x++) {
                        arr[y + i][x + j] |= st[y][x];
                    }
                }

                return true;
            }
        }
    }

    return false;
}

void rotate() {
    bool nst[15][15]{0};
    int nr = r;
    swap(r, c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            nst[i][j] = st[nr - j - 1][i];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            st[i][j] = nst[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int t = 0; t < k; t++) {
        fill_n(&st[0][0], 15 * 15, false);
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) 
                cin >> st[i][j];
        
        for (int j = 0; j < 4; j++) {
            if (chk())
                break;
                
            rotate();
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            arr[i][j] && ans++;

    cout << ans;
}