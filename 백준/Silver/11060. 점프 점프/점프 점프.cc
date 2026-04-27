#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> maze(n);
    for (int i = 0; i < n; i++)
        cin >> maze[i];

    vector<int> dp(n, INF);
    dp[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= maze[i]; j++) {
            if (i + j < n)
                dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    cout << (dp[n-1] == INF ? -1 : dp[n-1]);
}