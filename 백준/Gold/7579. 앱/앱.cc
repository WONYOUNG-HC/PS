#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int memory[110], cost[110];
int dp[10000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> memory[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    fill(dp, dp + m + 10, 1e9);
    
    for (int i = 1; i <= memory[1]; i++) {
        dp[i] = cost[1];
    } 

    for (int i = 2; i <= n; i++) {
        for (int j = m; j > memory[i]; j--) {
            dp[j] = min(dp[j], dp[j - memory[i]] + cost[i]);
        }

        for (int j = memory[i]; j > 0; j--) {
            dp[j] = min(dp[j], cost[i]);
        }
    }

    cout << dp[m];
}