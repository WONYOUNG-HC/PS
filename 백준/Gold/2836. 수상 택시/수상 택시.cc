#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int n, m;
vector<pll> v;

struct cmp {
    bool operator()(pll a, pll b) {
        return a.second < b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        ll a, b;

        cin >> a >> b;

        if (a > b) {
            v.push_back({b, a});
        }
    }

    sort(v.begin(), v.end());

    v.push_back({1e9 + 10, 1e9 + 10});

    priority_queue<pll, vector<pll>, cmp> pq;

    ll ans = m;

    for (auto pr : v) {
        if (!pq.empty() && pq.top().second < pr.first) {
            ll start = pq.top().first;
            ll end = pq.top().second;

            while (!pq.empty()) {
                start = min(start, pq.top().first);
                pq.pop();
            }

            ans += (end - start) * 2;
        }

        pq.push(pr);
    }

    cout << ans;
}