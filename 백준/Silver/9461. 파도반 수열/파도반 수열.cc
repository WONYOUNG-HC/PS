#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long int> dp(6, 1);
    dp[4]=2; dp[5]=2;

    int tc, n;
    cin >> tc;
    while (tc--) {
        cin >> n;
        while (dp.size() <= n)
            dp.push_back(dp[dp.size()-1] + dp[dp.size()-5]);
        cout << dp[n] << '\n';
    }
}