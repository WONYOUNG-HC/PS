#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        cin >> k;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < k; i++) {
            int x; cin >> x;
            pq.push(x);
        }

        ll ans = 0;
        while (pq.size() > 1) {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            
            pq.push(a + b);
            ans += a + b;
        } 

        cout << ans << '\n';
    }
}