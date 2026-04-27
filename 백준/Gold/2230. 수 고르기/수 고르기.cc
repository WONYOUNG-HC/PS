#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int& x : v) cin >> x;
    
    sort(v.begin(), v.end());

    int ans = 2e9 + 100;
    int left = 0, right = 0;

    while (left < n && right < n) {
        int dif = abs(v[right] - v[left]);
        if (dif >= m) {
            ans = min(ans, dif);
            left++;
        }
        else {
            right++;
        }
    }

    cout << ans;
}