#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    int k;
    cin >> m >> k;
    int b[m][k];
    for (int i=0; i<m; i++) {
        for (int j=0; j<k; j++) {
            cin >> b[i][j];
        }
    }

    int sum;
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            sum = 0;
            for (int l=0; l<m; l++) {
                sum += a[i][l] * b[l][j];
            }
            cout << sum << ' ';
        }
        cout << '\n';
    }
}