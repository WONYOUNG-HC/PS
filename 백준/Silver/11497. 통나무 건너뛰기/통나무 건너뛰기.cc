#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;

        vector<int> v(n);
        for (int& x : v) cin >> x;

        sort(v.begin(), v.end());

        int ans = 0;
        for (int i = 0; i < n - 2; i++)
            ans = max(ans, v[i + 2] - v[i]);

        ans = max(ans, max(v[1] - v[0], v[n - 1] - v[n - 2]));

        cout << ans << '\n';
    }
}