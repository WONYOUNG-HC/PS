#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i=0; i<n; i++)
        cin >> nums[i];

    vector<int> dp(n, 1);
    int len = 1, idx = 0;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }

        if (dp[i] > len) {
            len = dp[i];
            idx = i;
        }
    }

    cout << len << '\n';

    vector<int> lis;
    int k = idx;
    while (dp[k] != 1) {
        lis.push_back(nums[k]);
        pair<int, int> prev = {0, 0};
        for (int i=0; i<k; i++) {
            if (dp[i] > prev.first && nums[i] < nums[k])
                prev = {dp[i], i};
        }
        k = prev.second;
    }
    lis.push_back(nums[k]);

    reverse(lis.begin(), lis.end());
    for (int i : lis)
        cout << i << ' ';
}