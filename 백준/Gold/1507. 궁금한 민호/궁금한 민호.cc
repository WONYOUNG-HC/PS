#include <iostream>

using namespace std;

int n;
int arr[22][22], res[22][22];

bool floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == k || j == k)
                    continue;

                if (arr[i][j] == arr[i][k] + arr[k][j]) {
                    res[i][j] = 0;
                }
                else if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            res[i][j] = arr[i][j];
        }
    }


    int ans = -1;
    if (floyd()) {
        ans = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans += res[i][j];
            }
        }
    }

    cout << ans;
}