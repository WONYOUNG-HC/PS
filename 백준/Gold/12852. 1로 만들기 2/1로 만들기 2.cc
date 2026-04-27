#include <iostream>

using namespace std;

void MakeOne(int n) {
    int dp[n+1];
    int touch[n+1];

    dp[1] = 0; touch[1] = 0;
    for (int i=2; i<=n; i++) {
        int j;
        if (i % 6 == 0) {
            if (dp[i/3] < dp[i/2])
                j = i / 3;
            else
                j = i / 2;
        }
        else if (i % 3 == 0)
            j = i / 3;
        else if (i % 2 == 0)
            j = i / 2;
        else
            j = i - 1;

        if (dp[j] > dp[i-1])
            j = i - 1;
        dp[i] = dp[j] + 1;
        touch[i] = j;
    }

    cout << dp[n] << '\n';

    int i = n;
    cout << n << ' ';
    while (i > 1) {
        cout << touch[i] << ' ';
        i = touch[i];
    }
}

int main() {
    int n;
    cin >> n;
    MakeOne(n);
}