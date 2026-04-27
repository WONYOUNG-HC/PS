#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> nums(n+1);
    for (int i=1; i<=n; i++)
        cin >> nums[i];

    sort(nums.begin()+1, nums.end(), greater<>());

    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (i % 3 == 0)
            continue;
        ans += nums[i];
    }

    cout << ans;
}