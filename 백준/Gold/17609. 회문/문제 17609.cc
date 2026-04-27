#include <iostream>
#include <string>

using namespace std;

string str;

int recur(int l, int r, int cnt) {
    if (l >= r || cnt >= 2)
        return cnt;

    if (str[l] == str[r]) {
        return recur(l + 1, r - 1, cnt);
    } else {
        int cur;
        cur = recur(l + 1, r, cnt + 1);
        cur = min(cur, recur(l, r - 1, cnt + 1));
        return cur;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        cin >> str;

        cout << recur(0, str.length() - 1, 0) << '\n';
    }
}