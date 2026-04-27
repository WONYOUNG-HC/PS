#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int bin[n+1][k+1];

    for (int i=1; i<=n; i++) {
        for (int j=0; j<=min(i, k); j++) {
            if (j == 0 || j == i) bin[i][j] = 1;
            else bin[i][j] = (bin[i-1][j-1] + bin[i-1][j]) % 10007;
        }
    }

    cout << bin[n][k];
}