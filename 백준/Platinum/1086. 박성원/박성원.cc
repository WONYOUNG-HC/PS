#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int n, k;
string arr[20];
ll dp[(1 << 15) + 10][110];
ll powers[20];
ll remainders[20];

ll pow10_mod(int x) {
    int ret = 1;

    for (int i = 0; i < x; i++) {
        ret = ret * 10 % k;
    }

    return ret;
}

ll stoll_mod(string s) {
    ll ret = 0;

    for (char c : s) {
        ret = (ret * 10 + (c - '0')) % k;
    }

    return ret;
}

ll fact(ll x) {
    ll ret = 1;

    for (int i = 2; i <= x; i++) {
        ret *= i;
    }

    return ret;
}

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    //
    //
    //

    for (int i = 0; i < n; i++) {
        powers[i] = pow10_mod(arr[i].length());
        remainders[i] = stoll_mod(arr[i]);
    }

    //
    //
    //

    dp[0][0] = 1;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int remainder = 0; remainder < k; remainder++) {
            if (dp[mask][remainder] == 0) {
                continue;
            }

            for (int i = 0; i < n; i++) {
                int new_mask = mask | (1 << i);

                if (mask == new_mask) {
                    continue;
                }

                int new_remainder = (remainder * powers[i] + remainders[i]) % k;

                dp[new_mask][new_remainder] += dp[mask][remainder];
            }
        }
    }

    //
    //
    //

    ll cnt = dp[(1 << n) - 1][0];
    ll total = fact(n);

    cout << cnt / gcd(cnt, total) << "/" << total / gcd(cnt, total);
}