#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

ll n, k;
ll arr[500010];

bool f(ll mid) {
    ll i = lower_bound(arr, arr + n, mid) - arr;

    ll x = 0;
    for (; i < n; i++) {
        if (arr[i] - mid < 0)
            continue;

        x += arr[i] - mid;

        if (x > k)
            return false;
    }

    return x <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    ll left = 0, right = 1e12;
    while (left <= right) {
        ll mid = (left + right) / 2;

        if (f(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << left;
}