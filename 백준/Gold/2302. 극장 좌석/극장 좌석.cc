#include <iostream>

using namespace std;

int n, m;
int dp[40];
bool vip[50];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int v;
        
        cin >> v;
        vip[v] = true;
    }

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (vip[i] || vip[i - 1]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }

    cout << dp[n];
}