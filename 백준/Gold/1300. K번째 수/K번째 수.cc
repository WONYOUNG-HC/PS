#include <iostream>

using namespace std;
using ll = long long;

ll n, k;

bool f(ll mid) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += min(n, mid / i);

        if (cnt >= k) {
            return true;
        }
    }

    return cnt >= k;
}

int main() {
    cin >> n >> k;
    
    ll left = 1, right = n * n;
    while (left <= right) {
        ll mid = (left + right) / 2;

        if (f(mid))
            right = mid - 1;
        else   
            left = mid + 1;
    }

    cout << left;
}