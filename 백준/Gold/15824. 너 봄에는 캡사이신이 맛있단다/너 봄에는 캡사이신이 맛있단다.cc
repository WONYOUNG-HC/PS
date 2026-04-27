#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int n;
ll arr[300010];
ll pw[300010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    //
    //
    //

    pw[0] = 1;

    for (int i = 1; i <= n; i++) {
        pw[i] = (pw[i - 1] * 2) % mod;
    }

    //
    //
    //

    sort(arr, arr + n + 1);

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += arr[i] * pw[i - 1] % mod;
        ans -= arr[i] * pw[n - i] % mod;
        ans = (ans + mod) % mod;
    }

    cout << ans;
}