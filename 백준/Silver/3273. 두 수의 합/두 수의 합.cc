#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> v(n);
    for (int& x : v) cin >> x;

    int x; cin >> x;

    sort(v.begin(), v.end());

    int ans = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        if (v[left] + v[right] == x)
            ans++, left++;
        else if (v[left] + v[right] > x)
            right--;
        else
            left++;
    }

    cout << ans;
}