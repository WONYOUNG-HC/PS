#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, d;
int arr[510][510];
int narr[510][510];

void rotate() {
    int mid = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                narr[i][j] = arr[mid][j];
            } else if (i == mid) {
                narr[i][j] = arr[n - j - 1][j];
            } else if (i + j == n - 1) {
                narr[i][j] = arr[i][mid];
            } else if (j == mid) {
                narr[i][j] = arr[i][i];
            } else {
                narr[i][j] = arr[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = narr[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;

    cin >> tc;

    while (tc--) {
        cin >> n >> d;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        d = (d / 45) % 8;
        
        if (d < 0) {
            d = 8 + d;
        }

        for (int i = 0; i < d; i++) {
            rotate();
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}