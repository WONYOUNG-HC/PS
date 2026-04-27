#include <iostream>
#include <vector>

#define MOD 1'000'000'000

using namespace std;

int main() {
    int n; cin >> n;

    vector<vector<int>> bridge(n + 1, vector<int>(10));
    for (int i = 1; i <= 9; i++)
        bridge[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        bridge[i][0] = bridge[i-1][1];

        for (int j = 1; j <= 8; j++)
            bridge[i][j] = (bridge[i-1][j-1] + bridge[i-1][j+1]) % MOD;

        bridge[i][9] = bridge[i-1][8] % MOD;
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += bridge[n][i];
        ans %= MOD;
    }

    cout << ans;
}