#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int EditDistance(string& a, string& b);

int main() {
    string a, b;
    cin >> a >> b;

    cout << EditDistance(a, b);
}

int EditDistance(string& a, string& b) {
    int lenA = (int)a.size();
    int lenB = (int)b.size();

    vector<vector<int>> dp(lenA+1, vector<int>(lenB+1));
    for (int i=1; i<=lenA; i++)
        dp[i][0] = i;
    for (int j=1; j<=lenB; j++)
        dp[0][j] = j;

    for (int i=1; i<=lenA; i++) {
        for (int j=1; j<=lenB; j++) {
            int val = (a[i-1] == b[j-1]) ? 0 : 1;
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = min(dp[i][j] + 1, dp[i-1][j-1] + val);
        }
    }

    return dp[lenA][lenB];
}