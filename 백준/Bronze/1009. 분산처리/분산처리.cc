#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;

    while (tc--) {
        int a, b;
        cin >> a >> b;

        a %= 10;

        int m = a;
        for (int i = 0; i < b - 1; i++) {
            a = a * m % 10;
        }

        cout << (a == 0 ? 10 : a) << '\n';
    }
}