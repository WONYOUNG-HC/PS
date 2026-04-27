#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int RemoveSticker(int n, vector<vector<int>>& sticker);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<vector<int>> sticker(2);
        for (int i=0; i<2; i++) {
            sticker[i].resize(n);
            for (int j=0; j<n; j++) {
                cin >> sticker[i][j];
            }
        }

        cout << RemoveSticker(n, sticker) << '\n';
    }

    return 0;
}

int RemoveSticker(int n, vector<vector<int>>& sticker) {
    if (n == 1)
        return max(sticker[0][0], sticker[1][0]);

    int dp[2][n];

    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            dp[i][j] = sticker[i][j];
    dp[0][1] += sticker[1][0]; dp[1][1] += sticker[0][0];

    for (int i=2; i<n; i++) {
        dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + sticker[0][i];
        dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + sticker[1][i];
    }

    return max(dp[0][n-1], dp[1][n-1]);
}