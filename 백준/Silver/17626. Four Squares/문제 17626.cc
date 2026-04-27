#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int dp[50001];
    vector<int> root(1, 1);
    dp[1] = 1;


    int n;
    cin >> n;
    for (int i=2; i<=n; i++) {
        if (pow(int(sqrt(i)), 2) == i) {
            dp[i] = 1;
            root.push_back(i);
            continue;
        }

        dp[i] = 4;
        for (int j : root)
            dp[i] = min(dp[i], dp[j] + dp[i-j]);
    }

    cout << dp[n];
}