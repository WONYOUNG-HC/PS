#include <iostream>

using namespace std;

int n, l;
int arr[110][110], route[210][110];
bool vis[210][110];

bool pass(int row) {
    int* r = route[row];
    bool* v = vis[row];

    for (int i = 0; i < n - 1; i++) {
        if (abs(r[i] - r[i + 1]) > 1)
            return false;

        if (r[i] == r[i + 1] - 1) {
            for (int j = 0; j < l; j++) {
                if (i - j < 0 || v[i - j] || r[i] != r[i - j])
                    return false;
                v[i - j] = true;
            }
        }

        if (r[i] == r[i + 1] + 1) {
            for (int j = 1; j <= l; j++) {
                if (i + j >= n || v[i + j] || r[i + 1] != r[i + j])
                    return false;
                v[i + j] = true;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            route[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            route[n + i][j] = arr[j][i];
        }
    }

    int ans = 0;
    for (int i = 0; i < 2 * n; i++)
        pass(i) && ans++;

    cout << ans;
}