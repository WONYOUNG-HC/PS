#include <iostream>
#include <map>

using namespace std;
using ll = long long;

int n;
ll a[200010];
ll b[200010];
ll c[200010];
ll prefix[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    ll ans = 0;
    map<ll, ll> mp;

    mp[0] = 1;

    for (int i = 1; i <= n; i++) {
        c[i] = a[i] - b[i];
        prefix[i] = prefix[i - 1] + c[i];

        if (mp.find(prefix[i]) != mp.end()) {
            ans += mp[prefix[i]];
        }

        mp[prefix[i]] += 1;
    }

    cout << ans;
}