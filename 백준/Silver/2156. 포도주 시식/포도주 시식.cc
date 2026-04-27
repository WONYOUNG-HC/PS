#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MaxThree(const int& num1, const int& num2, const int& num3) {
    int num = max(num1, num2);
    return max(num, num3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> wine(n);
    for (int i=0; i<n; i++)
        cin >> wine[i];

    vector<int> dp(n);
    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = MaxThree(wine[0] + wine[1], wine[0] + wine[2], wine[1] + wine[2]);
    for (int i=3; i<n; i++)
        dp[i] = MaxThree(dp[i-1], dp[i-2] + wine[i], dp[i-3] + wine[i-1] +  wine[i]);

    cout << dp[n-1];
}