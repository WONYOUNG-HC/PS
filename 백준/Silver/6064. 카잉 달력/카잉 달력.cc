#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int ans = x; y %= n;

        while (ans <= m * n && ans % n != y)
            ans += m;

        cout << (ans > m * n ? -1 : ans) << '\n';
    }
}