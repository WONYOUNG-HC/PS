#include <iostream>
#include <deque>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int n, d;
ll arr[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //
    //
    //

    deque<pll> dq;
    ll ans = arr[0];

    dq.push_back({arr[0], 0});

    for (int i = 1; i < n; i++) {
        if (i - dq.front().second > d) {
            dq.pop_front();
        }

        ll prev = dq.empty() ? 0 : max(dq.front().first, 0LL);
        ll cur = prev + arr[i];

        ans = max(ans, cur);

        while (!dq.empty() && dq.back().first <= cur) {
            dq.pop_back();
        }

        dq.push_back({cur, i});
    }

    cout << ans;
}