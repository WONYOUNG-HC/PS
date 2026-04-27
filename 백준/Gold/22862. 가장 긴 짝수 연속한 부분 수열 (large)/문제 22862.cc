#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> even(n), odd(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        (a % 2 == 0 ? even[i] : odd[i]) = 1;
    }

    long long cur = even[0], dif = odd[0], ans = even[0];
    int left = 0, right = 0;
    while (right < n) {
        if (dif <= k) {
            ans = max(ans, cur);
            right++;
            cur += even[right];
            dif += odd[right];
        }
        else {
            cur -= even[left];
            dif -= odd[left];
            left++;
        }
    }
    if (dif < cur) ans = max(ans, cur);

    cout << ans;
}