#include <iostream>

#define INF ~(1<<31)

using namespace std;

int MinMulti(int n, const int* d);

int main() {
    int n, r, c;
    cin >> n;
    int d[n+1];

    cin >> r >> c;
    d[0] = r;
    for (int i=1; i<n; i++) {
        cin >> r >> c;
        d[i] = r;
    }
    d[n] = c;

    cout << MinMulti(n, d);
}

int MinMulti(int n, const int* d) {
    int dp[n+1][n+1];

    for (int i=1; i<=n; i++)
        dp[i][i] = 0;
    for (int diagonal = 1; diagonal <= n-1; diagonal++) {
        for (int i=1; i<=n-diagonal; i++) {
            int j = i + diagonal;
            int min = INF;
            for (int k=i; k<=j-1; k++) {
                int cnt = dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j];
                if (cnt < min) {
                    dp[i][j] = cnt;
                    min = dp[i][j];
                }
            }
        }
    }

    return dp[1][n];
}