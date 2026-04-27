#include <iostream>
#include <map>

using namespace std;

int n;
map<int, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;

        if (c == 1) {
            int x, w;
            cin >> x >> w;
            m[w] = x;
        }
        else {
            int w;
            cin >> w;
            cout << m[w] << '\n';
        }
    }
}