#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());

    int ans = 0;
    for (auto iter1 = nums.begin(); iter1 != nums.end(); iter1++) {
        for (auto iter2 = nums.begin(); iter2 != nums.end(); iter2++) {
            if (iter1 == iter2)
                continue;

            auto iter3 = lower_bound(nums.begin(), nums.end(), *iter1 - *iter2);

            while (iter3 == iter1 || iter3 == iter2) iter3++;

            if (*iter1 == *iter2 + *iter3) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}