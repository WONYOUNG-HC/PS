#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;

    int len1 = (int)str1.size();
    int len2 = (int)str2.size();
    vector<vector<int>> dp(len1+1, vector<int>(len2+1));

    for (int i=1; i<=len1; i++) {
        for (int j=1; j<=len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[len1][len2] << '\n';

    string lcs;
    int y = len1, x = len2;
    while (dp[y][x] != 0) {
        if (dp[y][x] == dp[y-1][x]) y = y-1;
        else if (dp[y][x] == dp[y][x-1]) x = x-1;
        else {
            lcs += str1[y-1];
            y = y-1;
            x = x-1;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs;
}