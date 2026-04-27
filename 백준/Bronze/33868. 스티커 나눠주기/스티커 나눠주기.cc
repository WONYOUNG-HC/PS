#include <iostream>

using namespace std;

int n;
int t, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    cin >> t >> b;

    for (int i = 1; i < n; i++) {
        int u, v;

        cin >> u >> v;

        t = max(t, u);
        b = min(b, v);
    }

    cout << t * b % 7 + 1;
}