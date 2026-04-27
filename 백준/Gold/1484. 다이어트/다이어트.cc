#include <iostream>

using namespace std;
using ll = long long;

ll g;

ll f(ll x, ll y) {
    return (x + y) * (x - y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> g;

    ll left = 1;
    ll right = 1;

    bool ans = false;

    while (true) {
        ll diff = f(right, left);
        if (diff == g) {
            ans = true;
            cout << right << '\n';
            right += 1;
        } else if (diff < g) {
            right += 1;
        } else {
            if (right - left == 1) {
                break;
            }

            left += 1;
        }
    }

    if (!ans) {
        cout << -1;
    }
}