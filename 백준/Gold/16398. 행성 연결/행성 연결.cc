#include <iostream>
#include <queue>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int n;
ll arr[1010][1010];
bool vis[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    ll ans = 0;
    priority_queue<pll, vector<pll>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        ll cost = pq.top().first;
        ll cur = pq.top().second;
        pq.pop();

        if (vis[cur])
            continue;
        vis[cur] = true;
        ans += cost;

        for (int i = 1; i <= n; i++) {
            if (vis[i])
                continue;

            pq.emplace(arr[cur][i], i);
        }
    }

    cout << ans;
}