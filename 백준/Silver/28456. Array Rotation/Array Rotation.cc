#include <iostream>
#include <cstring>

using namespace std;

int n, q;
int arr[110][110];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    cin >> q;
    for (int k = 0; k < q; k++) {
        int c; cin >> c;
        if (c == 1) {
            int r; cin >> r;
            int t = arr[r][n];

            for (int i = n; i > 1; i--)
                arr[r][i] = arr[r][i - 1];
            arr[r][1] = t;
        }
        else {
            int narr[110][110];
            memcpy(narr, arr, sizeof(arr));

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    narr[j][n - i + 1] = arr[i][j];
                }
            }

            memcpy(arr, narr, sizeof(arr));
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}