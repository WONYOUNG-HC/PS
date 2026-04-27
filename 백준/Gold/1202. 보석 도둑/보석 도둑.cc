#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>
#define M first
#define V second

using namespace std;

int n, k;
pll item[300010];
ll bag[300010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> item[i].M >> item[i].V;

    for (int i = 0; i < k; i++)
        cin >> bag[i];

    sort(item, item + n);
    sort(bag, bag + k);

    priority_queue<ll> pq;
    ll ans = 0; int idx = 0;

    for (int i = 0; i < k; i++) {
        while (idx < n && item[idx].M <= bag[i])
            pq.push(item[idx++].V);

        if (pq.empty())
            continue;

        ans += pq.top();
        pq.pop();
    }

    cout << ans;
}