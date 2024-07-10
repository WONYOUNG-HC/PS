#include <iostream>
#include <stack>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    ll ans = 0;
    stack<pll> st;
    for (int i = 0; i < n; i++) {
        ll now; 
        cin >> now;

        ll cnt = 1;
        while (!st.empty() && st.top().first <= now) {
            ans += st.top().second;

            if (st.top().first == now) {
                cnt += st.top().second;
            }

            st.pop();
        }

        if (!st.empty()) {
            ans++;
        }

        st.emplace(now, cnt);
    }

    cout << ans;
}