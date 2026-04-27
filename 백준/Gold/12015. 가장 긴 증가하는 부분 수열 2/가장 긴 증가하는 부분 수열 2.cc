#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int lis = 1;
    vector<int> dp(n+1, INF);
    dp[0] = -INF;
    for (int i=0; i<n; i++) {
        auto iter = upper_bound(dp.begin(), dp.begin() + (i+1), nums[i]);
        if (nums[i] < *iter && nums[i] != *(iter-1)) {
            *iter = nums[i];
            lis = max(lis, (int)(iter - dp.begin()));
        }
    }

    cout << lis;
}