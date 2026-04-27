#include <iostream>
#include <set>

using namespace std;

int n, q;
set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;

        if (a == 1) {
            s.insert(i);
        }
    }

    int cur = 0;
    for (int i = 0; i < q; i++) {
        int c, x;
        cin >> c;

        if (c == 1) {
            cin >> x;

            x -= 1;
            if (s.find(x) == s.end()) {
                s.insert(x);
            } else {
                s.erase(x);
            }
        } else if (c == 2) {
            cin >> x;

            cur = (cur + x) % n;
        } else {
            auto it = s.lower_bound(cur);

            if (s.size() == 0) {
                cout << -1 << '\n';
            } else if (it == s.end()) {
                cout << n - cur + *s.begin() << '\n';
            } else {
                cout << *it - cur << '\n';
            }
        }
    }
}