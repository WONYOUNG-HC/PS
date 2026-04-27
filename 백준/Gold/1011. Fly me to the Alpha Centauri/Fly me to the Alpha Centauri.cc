#include <iostream>
#include <cmath>

using namespace std;

int x, y;

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        cin >> x >> y;

        int len = y - x;
        int rt = sqrt(len);

        int ans = 0;

        if (rt * rt == len) {
            ans = 2 * rt - 1;
        } else {
            ans = 2 * rt;
        }

        if (len > rt * rt + rt) {
            ans += 1;
        }

        cout << ans << '\n';
    }
}