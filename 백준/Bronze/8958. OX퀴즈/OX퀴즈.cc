#include <iostream>
#include <string>

using namespace std;

void solve() {
    string str; cin >> str;

    int ans = 0, i = 0;
    for (char c : str) {
        if (c == 'O') {
            i++;
        }
        else {
            ans += (i * (i + 1)) / 2;
            i = 0;
        }
    }

    ans += (i * (i + 1)) / 2;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--)
        solve();
}