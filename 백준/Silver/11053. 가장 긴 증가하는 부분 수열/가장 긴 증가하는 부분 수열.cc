#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i=0; i<n; i++)
        cin >> nums[i];

    vector<int> dp(n, 1);
    int lis = 1;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        if (dp[i] > lis)
            lis = dp[i];
    }

    cout << lis;
}