#include <iostream>
#include <algorithm>

using namespace std;

int n;
int mn[2][3], mx[2][3], arr[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[j];
        }

        for (int j = 0; j < 3; j++) {
            mx[1][j] = 0, mn[1][j] = 1e9;
            for (int k = 0 ; k < 3; k++) {
                int d = j + k - 1;
                if (d < 0 || d > 2) {
                    continue;
                }

                mx[1][j] = max(mx[1][j], arr[j] + mx[0][d]);
                mn[1][j] = min(mn[1][j], arr[j] + mn[0][d]);
            }
        }

        for (int j = 0; j < 3; j++) {
            mx[0][j] = mx[1][j];
            mn[0][j] = mn[1][j];
        }
    }

    cout << *max_element(mx[0], mx[0] + 3) << ' ' << *min_element(mn[0], mn[0] + 3);
}