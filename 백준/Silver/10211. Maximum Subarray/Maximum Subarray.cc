#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int total_max = -1e9;
        int cur_max = -1e9;
        for (int i = 0; i < n; i++) {
            cur_max = max(cur_max + nums[i], nums[i]);
            total_max = max(total_max, cur_max);
        }

        cout << total_max << '\n';
    }
}